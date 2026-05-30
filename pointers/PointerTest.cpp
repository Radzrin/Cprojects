#include <iostream>


int main(){

    std::string word = "syrup";
    std::string* wordPointer = &word;


    std::cout << word << "\n";
    std::cout << &word << "\n";
    std::cout << wordPointer << "\n";
    std::cout << *wordPointer << "\n";



    return 0;
}