#include "GeneSplicer.hpp"


namespace pandemic{

    //Can dicovery a cure by throwing any cards, not neccery with the same color
    GeneSplicer& GeneSplicer::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        //Check if city has a research facility   
        if(this->board.cityToResearch[this->city]){
            //If the is cure with the givven color
            if( this->board.colorToCure[color] == false){
                for(City c : this->cards){

                    count+=1;
                    cardsToThrow.push_back(c);
                
                }
                //Only if there is enough cards to throw
                if (count >=5){
                    for(int i=0;i<5;++i){
                        City c = cardsToThrow.front();
                        this->cards.remove(c);
                        cardsToThrow.pop_front();
                    }
                    //Cure this color
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