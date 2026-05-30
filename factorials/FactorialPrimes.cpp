#include <string>
#include <iostream>
#include <cstdint>
#include <vector>
#include <algorithm>


std::string add(std::string n1, std::string  n2){
    int remainder = 0;
    std::string res;
    int i = n1.size();
    int j = n2.size();

    while(i != 0 || j != 0){
        int sum;
        if(i != 0)
            sum += n1[i--] - '0';

        if(j != 0)
            sum += n2[j--] - '0';    

        remainder = sum / 10;
        res += (sum  % 10) - '0';    
    }

    std::reverse(res.begin(), res.end());
    return res;
}

std::string subtract(std::string  n1, std::string n2){
    std::string temp;
    int borrow = 0;

    if(n2 > n1){
        temp = n1;
        n1 = n2;
        n2 = n1;
    }

    std::string res;

    int i = n1.size();
    int j = n2.size();

    while(i >= 0 || j >= 0){
        int dif = (n1[i--] - '0') - (n2[j--] - '0') - borrow;
        if(dif < 0){
            dif += 0;
            borrow = 1;
        }else{
            borrow = 0;
        }

        res += borrow + '0'; 
    }

    std::reverse(res.begin(), res.end());
    
    return res;
}

/**
 * using the karatsuba algorithm to calculate the sum of large integers
 * the function accepts a string type vector and calculate the sum of the last 2 elements
 * the function iterates through the vector backwards
 * the karatsuba algorithm is a command and conquor algorithm similar to merge sort that
 * takes 2 strings halves them recursively and multiplies them
 * 
 * for example if given a list: {123, 54, 2, 10} the function should do the following:
 * 
 * multiply 2*10 
 * remove the last 2 elements from the vector
 * add the sum to the back of the vector 
 * and perform a recursion until only 1 element remains
 */
std::string karatsubaString(std::vector<std::string> in){
    if(in.size() == 1){
        return in.at(0);
    }

    std::vector<std::string> nv;
    std::string x = in.at(in.size() - 1);
    std::string y = in.at(in.size() - 2);
    
    int sz = std::max(x.size(), y.size());

    if (sz == 1) 
    return std::to_string((x[0] - '0') * (y[0] - '0'));

    int halfX = x.size()/2;
    int halfY = y.size()/2;
    std::string x1 = x.substr(0, halfX);
    std::string x2 = x.substr(halfX);
    std::string y1 = y.substr(0, halfY);
    std::string y2 = y.substr(halfY);

    nv.push_back(x1);
    nv.push_back(y1);
    std::string ac = karatsubaString(nv);
    nv.front() = x2;
    nv.back()  = y2;
    std::string bd = karatsubaString(nv);
    
    nv.front() = add(x1,x2);
    nv.back()  = add(y1, y2);

    std::string add_ab = karatsubaString(nv);

    std::string subt = subtract(add_ab, add(ac, bd));

    nv.pop_back();
    nv.pop_back();
    std::string finsum = add(add(ac + std::string(2 * (sz - halfX), '0'), subt + std::string(sz - halfY, '0')), bd);
    in.pop_back();
    in.pop_back();
    in.push_back(finsum);

    return karatsubaString(in);
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
    
    
    return karatsubaString(nv);
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

   std::cout << factorial(4);
    return 0;
}