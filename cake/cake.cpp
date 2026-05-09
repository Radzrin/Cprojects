#include <unordered_map>
#include <iostream>
#include <cstdint>
/**
 * Write a function cakes(), which takes the recipe (unordered_map<string, int>) 
 * and the available ingredients (also an unordered_map<string, int>) 
 * and returns the maximum number of cakes Pete can bake (integer). 
 * For simplicity there are no units for the amounts 
 * (e.g. 1 lb of flour or 200 g of sugar are simply 1 or 200). 
 * Ingredients that are not present in the objects, can be considered as 0.
 */

using Ingredients = std::unordered_map<std::string, int>;

int cakes(const Ingredients& recipe, const Ingredients& available) {
    int num {INT32_MAX};
  if(recipe.size() > available.size())
    return 0;

for(std::pair<std::string, int> inl: recipe){
    if(!(available.find(inl.first)!= available.end())){
        return 0;
    }
    
    if((recipe.at(inl.first) > available.at(inl.first))){
        return 0;
    }else{
        if((available.at(inl.first) / recipe.at(inl.first)) < num ) 
            num = (int) (available.at(inl.first) / recipe.at(inl.first));  
    }
}
    
  return num;
}


int main(){
     Ingredients recipe    = {{"flour",  500}, {"sugar",  200}, {"eggs", 1}, {"honey", 4000}},
                    available = {{"flour", 1200}, {"sugar", 1200}, {"eggs", 5}, {"milk", 200}}; 
       //std::cout<< (cakes(recipe, available) ==  2);
        std::cout << "" << cakes(recipe, available) << "\n";
}