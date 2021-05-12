#include "Dispatcher.hpp"
#include <algorithm>
#include <list>
namespace pandemic{
    //Flying direct to c --> if there is a research facility in current city so can fly any where
    Dispatcher& Dispatcher::fly_direct(const City& c){
        list<City>::iterator it;
        //Check if the player has the card
        it = find(this->cards.begin(), this->cards.end(), c);
        if(this->city != c){
            if(this->board.cityToResearch[this->city]){
                this->city = c;
            }
            else{
                if(it != this->cards.end() ){
                    this->city = c;
                    this->cards.remove(c);
                }else{
                    throw invalid_argument("dont have the card");
                }
            }
        }
        else{
            throw invalid_argument("Cant fly from city to it self");
        }
        return *this;
    }

}