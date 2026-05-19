#include <iostream>
#include <vector>

/**
 * calculate fibunacci number of nth position recursively
 */
int fibunacci(int n){
    if(n <= 1)
        return n;

    return fibunacci(n - 1) + fibunacci(n - 2);
}

/**
 * calculating the fibunacci number of nth position
 * using the memoized solution
 */
int fibunacci(int n, std::vector<int> memo){
    if(memo[n] != NULL)
        return memo[n];

    if(n <= 1)
        return n;
    
    int result = fibunacci(n - 1) + fibunacci(n - 2);    
    memo.push_back(result);
    
    return result;
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