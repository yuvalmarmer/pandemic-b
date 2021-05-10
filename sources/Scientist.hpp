
#include <iostream>
#include <stdexcept>
#include <string>
#include "Player.hpp"

using namespace std;

namespace pandemic{
    class Scientist : public Player{
        public:
            Scientist(Board& b, City c):Player(b,c),n(4){};
            Scientist(Board& b, City c, int d):Player(b,c),n(d){};
            Scientist& discover_cure(const Color&);
            string role(){
                return "Scientist";
            };
            int n;
    };
}