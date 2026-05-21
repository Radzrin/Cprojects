#include <iostream>
#include <vector>
#include <algorithm>

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
    if(memo.at(n) != NULL)
        return memo.at(n);

    if(n <= 1)
        return n;
    
    int result = fibunacci(n - 1) + fibunacci(n - 2);    
    memo.push_back(result);
    
    return result;
}

/**
 * calculates the power of a number
 * ex: 2^2 = 4
 */
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


/**
 * Write a recursive function that implements binary search on a sorted array. 
 * The function should return the index of the target element if found, 
 * or -1 if the element is not present in the array. 
 * Your implementation should divide the search space in half with each recursive call.
 * 2 [1, 2, 3, 4, 5, 6, 7, 8]
 * [1, 2, 3, 4] [5, 6, 7, 8]
 * [1, 2, 3, 4]
 * [1, 2] [3, 4]
 * [1, 2] 
 * [1] [2]
 */
int binarySearch(int search, int nums[]){
    int index = 0;
    
    if(search > nums[index]){
    }else if(search < nums[index]){
    }

    if(search == nums[index])
        return index;


    return -1;
}



int main(){
   //std::cout << fibunacci(10) << "\n";
    //std::cout << power(2,10);
    int a[8] = {34, 2, 3, 4, 5, 6, 7, 8};

    std::cout << binarySearch(2, a);

    return 0;
}