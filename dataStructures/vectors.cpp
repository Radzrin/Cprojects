#include<iostream>
#include <cstdarg>
#include <string>


/**
 * custom vector data structure including its functions
 */

template<typename T>
class Vectors
{
private:
    int nmbOfElements;
    int capacity;
public:
    T* vecArr;
    
    

    Vectors()
    {
        nmbOfElements = 0;
        vecArr = new T[0];
        capacity = 0;
    }

    ~Vectors()
        {
           delete vecArr;
        }

        /**
         * insert value into the vector
         */
        template<typename Ty>
        void insert(Ty val){

            T*  tempArr = new T[nmbOfElements + 1];

            if(nmbOfElements == 0){
                vecArr = new T[1];
                vecArr[0] = val;
            }

            for(int i = 0; i < nmbOfElements; ++i){
                tempArr[i] = vecArr[i];
            }

            tempArr[nmbOfElements] = val;
            nmbOfElements++;
            vecArr = new T[nmbOfElements];


            for(int i = 0; i < nmbOfElements; ++i){
                vecArr[i] = tempArr[i];
            }

            delete tempArr;
        } 

        /**
         * remove element from index
         */
        void remove(int index){
            
            T*  tempArr = new T[nmbOfElements - 1];
            

            for(int i = 0; i < nmbOfElements; ++i){
                if(i == index){
                    tempArr[i] = vecArr[index + 1];    
                    i++;
                }    

                if(i > index){
                    tempArr[i] = vecArr[i + 1];
                    continue;
                }

                tempArr[i] = vecArr[i];
            }

            

            nmbOfElements--;
            vecArr = new T[nmbOfElements];


            for(int i = 0; i < nmbOfElements; ++i){
                vecArr[i] = tempArr[i];
            }

            delete tempArr;
        }   


        /**
         * removes an element at the end of the vector
         */
        void pop_back(){
            remove(nmbOfElements - 1);
        }
        
        /**
         * returns the index of a value if its in the vector
         */
        int find(T val){
            for(int  i = 0; i < nmbOfElements; ++i){
                if(vecArr[i] == val){
                    return i;
                }
            }
            std::cout << "value not found \n";
            return -1;
        }


        /**
         * returns the value at a given index
         */
        T at(int index){

            try
            {
                if(index >= nmbOfElements){
                    throw("out of bounds exception");
                }
            }
            catch(const std::string& e)
            {
                std::cout << e << '\n';
            }
            
            return vecArr[index];
        }

        /**
         * returns the first element
         */
        T front(){
            return vecArr[0];
        }

        /*
        * returns the last emelement
        */
        T back(){
            return vecArr[nmbOfElements -1];
        }

        /**
         * get the current vecArr of the vector
         */
        int getvecArr(){
            return nmbOfElements;
        }

        /**
         * returns the capacity of the vector
         */
        int getCapacity(){

            for(int i = 0; i < nmbOfElements; ++i){
                capacity += vecArrof(vecArr[i]);
            }
            return capacity;
        }

        /**
         * checks whether or not the vector is empty
         */
        bool empty(){
            return nmbOfElements > 0;
        }

        /**
         * print our the vector in a {v1, v2, v3,...} format
         */
        std::string toString(){
            std::string str = "{";
            for(int i = 0; i < nmbOfElements; ++i){
                str += std::to_string(vecArr[i]);

                if(i + 1 < nmbOfElements)
                    str += ",";
            }
            str += "}";
            return str;
        }

};











int main(){

    Vectors<int> v;

    v.insert(12);
    v.insert(100);
    v.insert(99);
    v.insert(43);
    v.insert(23);


    //v.getvecArr();

    std::cout <<  v.at(2)<< "\n";

    std::cout << v.find(23) << "\n";
    std::cout << v.toString() << "\n";


    v.remove(1);
    v.pop_back();
    
    std::cout << v.toString() << "\n";


    Vectors<double> v1;
    std::cout << v1.empty();
    v1.insert(12.5);
    v1.insert(134.45);
    //std::cout << v1.toString() << "\n";
    return 0;
}