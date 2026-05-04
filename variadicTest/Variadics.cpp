#include <iostream>
#include <cstdarg>
#include <string> 

/*
*   multiples a series of doubles and stops when the number is 0.0 
*   uses a while loop
*/
double multiplyAll(double first,...){
    double ans = 1.0;
    double num = first;
    va_list args;
    va_start(args, first);

    while(num != 0.0){
        ans *= num;
        num = va_arg(args, double);
    }

    va_end(args);

    return ans;
}

/**
 * A simple logging system using variatic arguments
 * (severity, timestamp, module name, message)
 * the severity status has to be 1 or 0
 * 1 is info 
 * 0 is error
 * the other arguments are strings
 * 
 */
void simpleLogger(int severity, ...){
    std::string status;
    std::string logTime;
    std::string moduleName;
    std::string logMessage;
    va_list args;
    va_start(args, severity);

    if(severity == 1){
        status = "[INFO]";
    }else{
        status = "[Error]";
    }

    logTime = va_arg(args, char*);
    moduleName = va_arg(args, char*);
    logMessage = va_arg(args, char*);
    // printf cannot interpret std::string objects so we use .c_str() to set a correct pointer
    printf("%s %s (%s): %s\n", status.c_str(), logTime.c_str(), moduleName.c_str(), logMessage.c_str());

    va_end(args);
}

/**
 * basically printf but only for %i and %f
 */
void miniPrint(const char* format, ...){
    std::string prtStr;
    std::string val;
    va_list args;
    va_start(args, format);

    prtStr = format;

    //loop through the string and replace the format with the number
    for(int i = 0; i < prtStr.length(); i++){
        if(prtStr[i] == '%' && prtStr[i + 1] == 'i'){
            val = std::to_string(va_arg(args, int));
            prtStr.replace(i,val.length(), val);
        }

        if(prtStr[i] == '%' && prtStr[i + 1] == 'f'){
            val = std::to_string(va_arg(args, double));
            prtStr.replace(i,2, val);
        }
    }

    va_end(args);
    
    std::cout << prtStr;
}

void mySuperLogger(const char* format, ...){
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

int main(){

    printf("answer: %F\n", multiplyAll(3.0, 5.0, 0.0, 2.0));

    simpleLogger(1, "12:00", "Network", "Connection Failed");
    simpleLogger(0, "13:00", "Database", "Could not query database");

    int n = 10;
    int w = 50;
    double c = 25.15;
    miniPrint("Result: %i apples weighing %ilb cost %f$\n", n, w, c);

    mySuperLogger("testing out vprint with %d variable argument.\n",1);

    return 0;
}