#include <iostream>
#include <string>

/**
 * reverses every character in a string
 * ex: "Hello World!" becomes  "!dlroW olleH"
 */
std::string reverseString(std::string str){
    return std::string(str.rbegin(), str.rend());
}

/**
 * reverses every word a string
 * ex: "Hello World!" becomes "World! Hello"
 */
std::string backwardsString(const std::string& str){
    std::string temp = "";
    int lengthofW {str.length() - 1};

    for(int i = str.length() - 1; i >= 0; i--){
        if(str[i] == ' '){
            temp += str.substr(i, lengthofW - i);
            lengthofW = i;
        }

        if(i == 0)
            temp += " " + str.substr(i, lengthofW);    
    }
    return temp;
}


bool isValidIPv4(const std::string& ip){

    

    return true;
}




int main(){

    
    std::cout << reverseString("this is a string to be reversed") << "\n";
    std::cout << backwardsString(" this is a string to be reversed") << "\n";
    return 0;
}