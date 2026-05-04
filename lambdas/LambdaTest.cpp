#include <iostream>
#include <functional> 


/**
 * passes a void lambda to a function
 */
void voidLambPass(std::function<void()> func){
    func();
}

/**
 * passes a int return lambda to a function
 */
void calcLambda(std::function<int(int a, int b)> func){
    std::cout << "this is from a lambda statement called within a function: " <<func(12, 14) << "\n";
}


int main(){

    auto message = [](){
        std::cout << "hello lambda \n";
    };

    auto multiplyNums = [](int x, int y){
        return x * y;
    };

    int varibaleOutsideLambda = 23;

    //this gets ne a copy of the value of varibaleOutsideLambda set before this lambda statement
    auto captureTestLambda = [varibaleOutsideLambda](){
        std::cout << "capture test: " <<varibaleOutsideLambda << "\n";
    };


    // this should let me get the most recent value of varibaleOutsideLambda even if it was set after this lambda statement
    auto captureTestLambda2 = [&varibaleOutsideLambda](){
        std::cout << "capture test using reference & : " <<varibaleOutsideLambda << "\n";
    };

    varibaleOutsideLambda = 14;

    //passing a lambda to a function
    voidLambPass(message);
    calcLambda(multiplyNums);
    captureTestLambda();
    captureTestLambda2();


    return 0;
}