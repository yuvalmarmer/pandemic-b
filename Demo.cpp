
#include "Board.hpp"
#include "Player.hpp"

using namespace std;
using namespace pandemic;

int main(){
    Board b;
    Player player{b,City::Algiers};
    // player.drive(City::Cairo); // player drive to neighbor city
    
    player.take_card(City::Algiers)
            .take_card(City::Cairo); // player takes those cards back
    
    // player.fly_charter(City::Algiers).fly_charter(City::Cairo); // order is wrong here

    // player.take_card(City::Algiers); // player takes back this card

    player.fly_charter(City::Cairo);//.fly_charter(City::Algiers); // fly_charter and back
    player.fly_charter(City::Algiers);

    return 0;
}