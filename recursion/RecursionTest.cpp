#include <iostream>


int fibunacci(int n){
    if(n <= 1)
        return n;

    return fibunacci(n - 1) + fibunacci(n - 2);
}

double power(double base, int exponent){
    if(exponent == 0)
    return 1.0;

    if(exponent < 0){
        base = 1 / base;    
        exponent *= -1; 
    }

    if(exponent == 1)
        return base;

    base *= power(base , exponent -= 1);

    return base;
}



int main(){
   //std::cout << fibunacci(10) << "\n";
    std::cout << power(2,10);
    return 0;
}