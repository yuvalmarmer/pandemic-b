#include "FieldDoctor.hpp"
#include <algorithm>

namespace pandemic{
    
    //Can treat any city that connected to current city
    FieldDoctor& FieldDoctor::treat(const City& c){
        std::list<City>::iterator it;
    
        it = find(this->board.cityConnectionMap[this->city].begin(), this->board.cityConnectionMap[this->city].end(), c);   
        if(it != this->board.cityConnectionMap[this->city].end() || this->city == c){
            //Check if there is pandemic in the city
            if(this->board.cityToPandemic[c]>0){
                //Check if there is a cure
                if(this->board.colorToCure[this->board.cityColorMap[c]]){
                    this->board.cityToPandemic[c] = 0;
                }
                else{
                    this->board.cityToPandemic[c] -= 1;
                }
            }
            else{
                throw invalid_argument("Cant treat city that dosnt have a pandemic");
            }
        }
        else{
            throw invalid_argument("The city is not a neighbor");
        }
        return *this;
    }

}