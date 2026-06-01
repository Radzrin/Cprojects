#include <iostream>
#include <math.h>


int main(){

    int los {5};
    float area = (1.0/4.0) * sqrt(5 * (5+2 * sqrt(5))) * pow(los, 2);

    std::cout << "a pentagon with sides of length " << los << " cm has an area equal to " << area << " cm^2";

    return 0;
}

