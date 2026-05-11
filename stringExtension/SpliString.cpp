#include <iostream>
#include <string>
#include <vector>

/**
 * Complete the solution so that it splits the string into strings of two characters in a list/array 
 * (depending on the language you use). If the string contains an odd number of characters then it should 
 * replace the missing second character of the final pair with an underscore ('_').
 * 
 * examples:
 * 'abc' =>  ['ab', 'c_']
* 'abcdef' => ['ab', 'cd', 'ef']
 */
std::vector<std::string> solution(const std::string &s)
{
    std::vector<std::string> letters;
    std::string combination = "";
    for(int i = 0; i < s.length();  i += 2){
        combination = "";
        if(i != s.length() - 1){
            combination += s[i];
            combination += s[i + 1];
            letters.push_back(combination);
            continue;
        }else{
            combination = s[i];
            letters.push_back(combination + "_");
        }
        
    }
    return letters;



int main(){
    std::string str = "abcde";
    std::cout << solution(str).at(0);

    return 0;
}