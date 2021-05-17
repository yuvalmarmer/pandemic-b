#include "Scientist.hpp"


namespace pandemic{

    //Can dicover a cure with less cards the 5, the parameter givven in the constructor
    Scientist& Scientist::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        //Check if city has a research facility   
        if(this->board.cityToResearch[this->city] ){
            //If the is cure with the givven color
            if( !this->board.colorToCure[color]){
                for(City c : this->cards){
                    if(this->board.cityColorMap[c]==color){
                        count+=1;
                        cardsToThrow.push_back(c);
                    }
                }
                //Only if there is enough cards to throw
                if (count >=this->n){
                    for(int i=0;i<this->n;++i){
                        City c = cardsToThrow.front();
                        this->cards.remove(c);
                        cardsToThrow.pop_front();
                    }
                    this->board.colorToCure[color] = true;
                }
                else{
                    throw invalid_argument("Less then 5 cards");
                }
            }
        }
        else{
            throw invalid_argument("Already have cure");
        }
        return *this;
    }

}