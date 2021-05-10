
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Medic : public Player{
        public:
            Medic(Board& b, City c):Player(b,c){};
            Medic& treat(const City&);
            Medic& drive(const City&);
            Medic& fly_direct(const City&);
            Medic& fly_charter(const City&);
            Medic& fly_shuttle(const City&);
            string role(){
                return "Medic";
            };
    };
}