#include "Researcher.hpp"

namespace pandemic{
        Researcher& Researcher::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        if(this->board.colorToCure[color] == false){
            for(City c : this->cards){
                if(this->board.cityColorMap[c]==color){
                    count+=1;
                    cardsToThrow.push_back(c);
                }
            }
            if (count >=5){
                for(int i=0;i<5;++i){
                    City c = cardsToThrow.front();
                    this->cards.remove(c);
                    cardsToThrow.pop_front();
                }
                this->board.colorToCure[color] = true;
            }
            else{
                throw invalid_argument("Dont have the needed cards");
            }
        }
        return *this;

    }

}