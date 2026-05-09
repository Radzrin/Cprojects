#include <iostream>

/**
 * print "Hello, world!" without the letters "Helo wrd"
 * this rule also applies to the code so for loops would be banned for containing "o"
 * the words "std", "string" and "return" are immune
 */
std::string f() 
{ 
 std::string mn {'J' - 2, 'g' - 2, 'n' - 2, 'n' - 2, 'q' - 2, '.' - 2, '"' - 2, 'y' - 2, 'q' - 2, 't' - 2, 'n' - 2, 'f' - 2, '#' - 2 };
    return  mn;
}

int main(){

    std::cout << f();
    return 0;
}