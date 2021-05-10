#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"
#include "City.hpp"
#include <algorithm>

using namespace std;

namespace pandemic{ 


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

    Player& Player::discover_cure(const Color& color){
        int count = 0;
        list<City> cardsToThrow;
        if(this->board.cityToResearch[this->city]){
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
                    throw invalid_argument("Less then 5 cards");
                }
            }
        }
        else{
            throw invalid_argument("Already have cure");
        }
        return *this;

    }
    Player& Player::drive(const City& c){

        std::list<City>::iterator it;
        // Fetch the iterator of element with value 'the'
        list<City> connList = this->board.cityConnectionMap[this->city];
        it = find(connList.begin(), connList.end(), c);
        if(it != connList.end()){
            this->city = c;
        }
        else{
            throw invalid_argument("Bad city");
        }
        return *this;

    }
    
    Player& Player::fly_charter(const City& c){

        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), this->city);

        if(it != this->cards.end() && this->city != c){
            this->cards.remove(this->city);
            this->city = c;
        }
        else{
            throw invalid_argument("You dont have this cards");
        }

        return *this;
    }

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
    Player& Player::fly_direct(const City& c){
        list<City>::iterator it;
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
    Player& Player::build(){
        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), this->city);
        if(it != this->cards.end()){
            if(this->board.cityToResearch[this->city] == false){
                this->cards.remove(this->city);
                this->board.cityToResearch[this->city]=true;
            }
        }
        else{
            throw invalid_argument("You dont have this card");
        }
        return *this;

    }

    Player& Player::take_card(const City& c){
        list<City>::iterator it;
        it = find(this->cards.begin(), this->cards.end(), c);
        if(it == this->cards.end()){
            this->cards.push_back(c);
        }
        return *this;

    }

    Player::Player(Board &b, City c):board(b),city(c){
    }
}