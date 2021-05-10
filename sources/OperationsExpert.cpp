
#include "OperationsExpert.hpp"

namespace pandemic{
    
    OperationsExpert& OperationsExpert::build(){
        //Build reacher anywhere he wants
        if(this->board.cityToResearch[this->city] == false){
            this->board.cityToResearch[this->city]=true;
        }
        return *this;
    }
}