
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class GeneSplicer : public Player{
        public:
            GeneSplicer(Board& b, City c):Player(b,c){};
            GeneSplicer& discover_cure(const Color&);
            string role(){
                return "GeneSplicer";
            };
    };
}