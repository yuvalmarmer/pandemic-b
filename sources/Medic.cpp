#include "Medic.hpp"
#include <algorithm>

namespace pandemic{
    //Treat the pandmic to 0
    Medic& Medic::treat(const City& c){
        std::list<City>::iterator it;
        
    
        //Check if there is pandemic in the city
        if(this->board.cityToPandemic[c]>0){
            this->board.cityToPandemic[c] = 0;
        }
        else{
            throw invalid_argument("Cant treat city that dosnt have a pandemic");
        }
    
      
        return *this;
    }

    //If the city color already have a cure automaticly cure it 
    Medic& Medic::drive(const City& c){

        std::list<City>::iterator it;
        // Fetch the iterator of element with value 'the'
        list<City> connList = this->board.cityConnectionMap[this->city];
        it = find(connList.begin(), connList.end(), c);
        if(it != connList.end()){
            if(this->board.colorToCure[this->board.cityColorMap[c]]){
                this->board.cityToPandemic[c]=0;
            }
            this->city = c;
        }
        else{
            throw invalid_argument("Bad city");
        }
        return *this;

    }
    
    //If the city color already have a cure automaticly cure it 
    Medic& Medic::fly_charter(const City& c){
        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), this->city);
        if(it != this->cards.end() ){
            if(this->board.colorToCure[this->board.cityColorMap[c]]){
                this->board.cityToPandemic[c]=0;
            }
            this->city = c;
            this->cards.remove(this->city);
        }
        return *this;
    }
    
    //If the city color already have a cure automaticly cure it   
    Medic& Medic::fly_shuttle(const City& c){
        //If current city has a research facility
        if(this->board.cityToResearch[this->city] && this->city != c){
            if(this->board.cityToResearch[c]){
                if(this->board.colorToCure[this->board.cityColorMap[c]]){
                    this->board.cityToPandemic[c]=0;
                }
                this->city = c;
            }
            else{
                throw invalid_argument("target city dosnt have a research facility");
            }
        }
        else{
            throw invalid_argument("Current city dosnt have a research facility");
        }
        
        return *this;

    }
    
    //If the city color already have a cure automaticly cure it   
    Medic& Medic::fly_direct(const City& c){
        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), c);
        if(it != this->cards.end() )
        {
            if(this->board.colorToCure[this->board.cityColorMap[c]]){
                this->board.cityToPandemic[c]=0;
            }
            this->city = c;
            this->cards.remove(c);
        }
        else{
             throw invalid_argument("Dont have destination card");
        }
        return *this;

    }
}