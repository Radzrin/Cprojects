#include <string>
#include <iostream>

/**
 * Given a string that includes alphanumeric characters ("3a4B2d") 
 * return the expansion of that string: The numeric values represent
 * the occurrence of each letter following that numeric value. 
 * There should be no numeric characters in the final string.
 * 
 * Examples:
 * "3Lsv2ab" => "LLLsssvvvaabb"
 * "1s7H99K" => "sHHHHHHHKKKKKKKKK"
 */
std::string string_expansion(const std::string& s) {
    std::string tmp = "";
  int multiply = 1;
    for(int i = 0; i < s.length(); i++){
      if(!std::isdigit(s[i])){
            tmp += std::string(multiply, s[i]);
            continue;
        }
      
      if(std::isdigit(s[i]) && i + 1 == s.length()){
        continue;
      }
      
        if(std::isdigit(s[i]) && !std::isdigit(s[i + 1])){
            multiply = s[i] - '0';
            tmp += std::string(multiply, s[i + 1]);
            i++;
            continue;
        }
  }
  return tmp;
}


int main(){

    std::cout << string_expansion("1s7H99K") << "\n";
    std::cout << string_expansion("99") << "\n";
    std::cout << string_expansion("9E9") << "\n";
    std::cout << string_expansion("3EAb9") << "\n";
    std::cout << string_expansion("3Lsv2ab") << "\n";
    std::cout << string_expansion("1a1") << "\n";

    std::cout << string_expansion("1a1") == "a";

    return 0;
}