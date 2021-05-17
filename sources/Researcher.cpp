#include "Researcher.hpp"

namespace pandemic{
    //Can disocver a cure any where he wants
    Researcher& Researcher::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        //If the is cure with the givven color
        if(!this->board.colorToCure[color]){
            for(City c : this->cards){
                if(this->board.cityColorMap[c]==color){
                    count+=1;
                    cardsToThrow.push_back(c);
                }
            }
            //Only if there is enough cards to throw
            if (count >=Board::NunOfCards){
                for(int i=0;i<Board::NunOfCards;++i){
                    City c = cardsToThrow.front();
                    this->cards.remove(c);
                    cardsToThrow.pop_front();
                }
                //Cure this color
                this->board.colorToCure[color] = true;
            }
            else{
                throw invalid_argument("Dont have the needed cards");
            }
        }
        return *this;

    }

}