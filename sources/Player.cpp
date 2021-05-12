#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#include "City.hpp"
#include <algorithm>

using namespace std;

namespace pandemic{ 

    //Treat cure by city
    Player& Player::treat(const City& c){
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
        return *this;
    }
    
    //Discover cure by color
    Player& Player::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        //Check if city has a research facility   
        if(this->board.cityToResearch[this->city]){
            //If the is cure with the givven color
            if(this->board.colorToCure[color] == false){
                for(City c : this->cards){
                    if(this->board.cityColorMap[c]==color){
                        count+=1;
                        cardsToThrow.push_back(c);
                    }
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
   
    //Drive to neerby city
    Player& Player::drive(const City& c){

        std::list<City>::iterator it;
        list<City> connList = this->board.cityConnectionMap[this->city];
        //Search if the city is connected to current city
        it = find(connList.begin(), connList.end(), c);
        if(it != connList.end()){
            this->city = c;
        }
        else{
            throw invalid_argument("Bad city");
        }
        return *this;

    }
    
    //Fly charter 
    Player& Player::fly_charter(const City& c){

        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), this->city);
        //Check if the player has card of the givven city
        if(it != this->cards.end() && this->city != c){
            this->cards.remove(this->city);
            this->city = c;
        }
        else{
            throw invalid_argument("You dont have this cards");
        }

        return *this;
    }

    //Fly shuttle
    Player& Player::fly_shuttle(const City& c){
        //If current city has a research facility
        if(this->board.cityToResearch[this->city] && this->city != c){
            if(this->board.cityToResearch[c]){
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
   
    //Fly direct
    Player& Player::fly_direct(const City& c){
        list<City>::iterator it;
        //Check if the player has card of the givven city
        it = find(this->cards.begin(), this->cards.end(), c);
        if(it != this->cards.end() && this->city != c){
            this->city = c;
            this->cards.remove(c);
        }
        else{
            throw invalid_argument("You dont have this card");
        }
        return *this;

    }

    //Build 
    Player& Player::build(){
        list<City>::iterator it;
        //Check if the player has card of the current city
        it = find(this->cards.begin(), this->cards.end(), this->city);
        if(it != this->cards.end()){
            if(this->board.cityToResearch[this->city] == false){
                //Throw the card and build a research facility
                this->cards.remove(this->city);
                this->board.cityToResearch[this->city]=true;
            }
        }
        else{
            throw invalid_argument("You dont have this card");
        }
        return *this;

    }

    //Take card
    Player& Player::take_card(const City& c){
        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), c);
        if(it == this->cards.end()){
            this->cards.push_back(c);
        }
        return *this;

    }

    //Player constructor
    Player::Player(Board &b, City c):board(b),city(c){}
}