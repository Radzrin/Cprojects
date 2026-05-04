#include <iostream>
#include <vector>
#include <cstdarg>

/**
 * handles addition and multiplicatiion 
 */
double addition(std::string operation, double num1, double num2){

    if(operation._Equal("+")){
        return num1 + num2;
    }else if(operation._Equal("*")){
        return num1 * num2;
    }

    return 0.0;
}

/*
    takes care of any sort of subtraction like operations
    testing out variadic argument (var...)

    @var va_list: creates a variatic list
    @var __va_start(va_list, t): allows us to access the variatic argument
    @var va_arg: fetches the next element in the list
    @var va_end: ends traversal of variadic Sargument and cleans up ap
 */
double subsctraction(std::string operation, double num ...){
    va_list argsList;
    va_start(argsList, num);
    double ans = 0.0;
    double n1 = num;
    double n2 =  va_arg(argsList, double);

    if(operation._Equal("/")){
        ans =  n1 / n2;
        va_end(argsList);
        return ans;

    }else if(operation._Equal("-")){
        ans = n1 - n2;
        va_end(argsList);
        return ans;
    }

    va_end(argsList);
    return 0.0;
}





int main(){

    
    double num1;
    double num2;
    std::string operation;

    while(true){
        std::cout << "insert a number\n";
        std::cin >> num1;
        std::cout << "insert an operation\n";
        std::cin >> operation;
        std::cout << "insert a number\n";
        std::cin >> num2;

        if(operation._Equal("/") || operation._Equal("-")){
            std::cout << subsctraction(operation, num1, num2) << "\n";
        }else{
            std::cout << addition(operation, num1, num2)<< "\n";
        }


    }

    std::cout << __cplusplus << '\n';
    


return 0;
}