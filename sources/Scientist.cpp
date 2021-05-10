#include "Scientist.hpp"


namespace pandemic{
        Scientist& Scientist::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        
        if(this->board.cityToResearch[this->city] ){
            if( this->board.colorToCure[color] == false){
                for(City c : this->cards){
                    if(this->board.cityColorMap[c]==color){
                        count+=1;
                        cardsToThrow.push_back(c);
                    }
                }
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