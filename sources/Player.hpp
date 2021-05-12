#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include "Color.hpp"
#include "Board.hpp"

using namespace std;

namespace pandemic{
    class Player{
        public:
            //Simple Player functions
            virtual Player& drive(const City&);
            virtual Player& fly_direct(const City&);
            virtual Player& fly_charter(const City&);
            virtual Player& fly_shuttle(const City&);
            virtual Player& build();
            virtual Player& discover_cure(const Color&);
            virtual Player& treat(const City&);
            Player& take_card(const City&);

            //Return the role 
            virtual string role(){
                return "Player";
            };

            //Constructor
            Player(Board &b , City c);
            
            //Properties
            Board& board;
            City city;
            list<City> cards;
    };
}