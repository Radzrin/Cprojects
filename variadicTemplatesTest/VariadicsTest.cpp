#include <iostream>
#include <cstdarg>


//base case
int countInt(){
    return 0;
}

/**
 * counts the number of ints in the input
 * ex: countInt(1, "abc", 23.43, 2); should return 2
*/
template<typename T, typename... args>
int countInt(T first, args... arg){
    bool isInt = std::is_same<int, T>::value;
    return isInt + countInt(arg...);
}


//base case
int printLines(){
    return 0;
}

/**
 * prints every arguments followed by a newline 
 * for example　printLines(1, 2.4, "test");　's output should be：
 *  1
 * 2.4
 * test
 */
template<typename T, typename... args>
int printLines(T first, args... arg){
    std::cout << first << "\n";
    return printLines(arg...);
}

//base case
void doubled(){}

/**
 * takes in numbers (double, int, etc.), doubles them and prints out the values
 */
template<typename T, typename... args>
void doubled(T first, args... arg){
    std::cout << first * 2 << ",";
    doubled(arg...);
}

//base case
bool hasNegative(){
    return false;
}

/**
 * accepts a bunch of numebers and if at least 1 of the numbers 
 * are negative it should return true
 * 
 */
template<typename T, typename... args>
bool hasNegative(T first, args... arg){
    if(first < 0)
        return true;


    return hasNegative(arg...);
}

//base case
template<typename T>
void shout(T last){
    std::cout << last << "!" << std::endl;
}

/**
 * prints every variable sent to the function followed by a ","
 * except for the last varible which is followed by a "!"
 * if there's only 1 element it should only print out that variable followed by a "!"
 */
template<typename T, typename... args>
void shout(T first, args...arg){
    std::cout << first << ", ";
    shout(arg...);    
}



int main(){

    std::cout << countInt(1, "abc", 23.43, 2) << "\n";
    printLines(1, 2.4, "test", 34.5f, 'f');
    std::cout << "\n" << "doubling numbers\n";
    doubled(1, 4, 4.5, 29.5);
    std::cout << "\n" << "negative number\n";
    std::cout << "list with a negative: " << hasNegative(1, 2, 4.5, -2, 45) << "\n";
    std::cout << "list without a negative: " << hasNegative(1, 2, 4.5, 76, 45) << "\n";
    std::cout << "\n" << "shout\n";
    shout(1, 35, "test");
    shout("hello", 1, "test");

    return 0;
}