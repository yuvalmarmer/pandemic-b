#include "Virologist.hpp"
#include <algorithm>

namespace pandemic{
    //Can treat any city by throwing there card
    Virologist& Virologist::treat(const City& c){
        std::list<City>::iterator it;
        
        it = find(this->cards.begin(), this->cards.end(), c);
        if(this->city != c){
            if(it != this->cards.end()){
                this->cards.remove(c);
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
                throw invalid_argument("You dont have this card");
            }
        }
        else{
                    //Check if there is pandemic in the city
            if(this->board.cityToPandemic[c]>0 && this->city == c){
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
    return *this;
    }
}