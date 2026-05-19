#include <string>
#include <iostream>
#include <cstdint>
#include <vector>
#include <cmath>


std::string string64(std::vector<std::string> in){
    std::string big128Int = "";
    std::vector<std::string> nv;
    int w = in.size() - 1;
    long long int sum = 0;
    int remainder = 0;

    if(in.size() == 1){
        return in.at(0);
    }

    while(in.size() > 0){
        for (int i = in.at(w).length() - 1; i >= 0; i--){
            for (int j = in.at(w - 1).length() - 1; j >= 0; j--){

                    if(in.at(w - 1).length()  > in.at(w).length() ){
                        sum +=  ((in.at(w)[i]- '0') * (in.at(w - 1)[j] - '0')) * (p) * pow(10, in.at(w).length() - 1 - i));
                    }else{
                        sum +=  ((in.at(w)[i]- '0') * (in.at(w - 1)[j] - '0')) * (pow(10, in.at(w).length() - 1 - i) * pow(10, in.at(w - 1).length() - 1 - j));
                    }
            }
        }
        in.pop_back();
        in.pop_back();

        big128Int = std::to_string(sum);
        nv.push_back(big128Int);
        
        if(in.size() == 1){
            nv.push_back(in.at(0));
            in.pop_back();
        }

        w = in.size() - 1;
        sum = 0;
    }

    

    return string64(nv);
}


std::string factorial(int factorial){
    std::vector<std::string> nv;
    int64_t ans = 1;


    if(factorial == 0)
        return "";

    for( int  i = 1; i <= factorial; i++){
        ans *= i;

        if(i % 2 == 0){
            nv.push_back(std::to_string(ans));
            ans = 1;
        }else if( i % 2 != 0 && i == factorial){
            nv.push_back(std::to_string(ans));
        }

    }
    
    
    return string64(nv);
}

std::string decomp(int n) {
  std::string tmp;

  return tmp;
}

int main(){

    //std::cout << factorial(2);
    /* int64_t a = 2432902008176640000;
    int64_t  d;
    std::string ab = "";
    while(a != 0){
        d = a % 10;
        ab += d;
        a /= 10;

        std::cout<< d;
    }

    std::cout << ab; */
   // std::cout << cd;

   std::cout << factorial(300);
    return 0;
}