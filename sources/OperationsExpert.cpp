
#include "OperationsExpert.hpp"

namespace pandemic{
    //Build reacher anywhere he wants without throwing a card 
    OperationsExpert& OperationsExpert::build(){
        if(!this->board.cityToResearch[this->city]){
            this->board.cityToResearch[this->city]=true;
        }
        return *this;
    }
}