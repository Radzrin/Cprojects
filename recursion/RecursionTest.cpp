#include <iostream>


int fibunacci(int n){
    if(n <= 0)
        return n;

    return fibunacci(n - 1) + fibunacci(n - 2);
}



int main(){
    std::cout << fibunacci(10);
    return 0;
}