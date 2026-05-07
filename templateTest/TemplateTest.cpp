#include <iostream>
#include <cstdarg>


/**
 * test template 
 *
*/
template<typename T>
T add(T a, T b){
    return a + b;
}

/**
 * compares the sizes of 2 variables of identical datatypes and returns the biggest one
 */
template<typename T>
T mymax(T val, T val2){
    if(val < val2)
        return val2;

    return val;    
}

/**
 * swapping variable reference values
 */
template<typename T>
void myswap(T &val1 ,T &val2){
    T temp;
    temp = val1;
    val1 = val2;
    val2 = temp;
}

/**
 * comparing 2 numbers that may or may not be of different datatypes
 * converts both to doubles and returns the biggest number
 */
template<typename T1, typename T2>
double compare(T1 val1, T2 val2){
    if((double) val1 < (double) val2)
        return (double)val2;
    return (double)val1;    

}

/**
 * base case to prevent infinite looping
 */
int sumAll(){
    return 0;
}

/**
 * takes in random numbers (at least 1) and  sums them all up
 * uses recursion
 */
template<typename T, typename... Args>
T sumAll(T first, Args... args){
    return first + sumAll(args...);
}


/**
 * testing out the arrow return feature
 */
auto main() -> int{
    
    std::cout << add<double>(12.4, 3.12) << "\n";
    std:: cout << add<int>(12, 3) << "\n";

    int a = 12;
    int b = 23;
    double c = 45.6;
    double d = 2.4;
    char e = 'z';
    char f = 'a';
    float g = 34.45f;

   printf("here's the max between %d and %d:  %d\n", a, b, mymax<int>(a,b));
   printf("here's the max between %.2f and %.2f:  %.2f\n", c, d, mymax<double>(c,d));
   printf("here's the max between %c and %c:  %c\n", e, f, mymax<char>(e,f));

    printf("e = '%c' and f = '%c', ", e, f);
    myswap(e, f);
    printf("now  e = '%c' and f = '%c'\n", e, f);

    printf("comparing the float %.2f with the int %d: biggest is %.2f\n", g, a, compare<double>(g,a));

    std::cout << "summing a random set of an unknown number of numbers using recursion" << sumAll<int>(1,2,3,4,5) << std::endl;

}