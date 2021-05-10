#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>      

using namespace std;
namespace pandemic{
    std::ostream& operator<< (std::ostream& os, const Board& n){
        return os;
    }
    void Board::initMaps(){
        
        this->stringToCity["SanFrancisco"] = City::SanFrancisco;
        this->stringToCity["Chicago"] = City::Chicago;
        this->stringToCity["Montreal"] = City::Montreal;
        this->stringToCity["NewYork"] = City::NewYork;
        this->stringToCity["Atlanta"] = City::Atlanta;
        this->stringToCity["Washington"] = City::Washington;
        this->stringToCity["Madrid"] = City::Madrid;
        this->stringToCity["London"] = City::London;
        this->stringToCity["Essen"] = City::Essen;
        this->stringToCity["Milan"] = City::Milan;
        this->stringToCity["Paris"] = City::Paris;
        this->stringToCity["StPetersburg"] = City::StPetersburg;

        this->stringToCity["LosAngeles"] = City::LosAngeles;
        this->stringToCity["MexicoCity"] = City::MexicoCity;
        this->stringToCity["Miami"] = City::Miami;
        this->stringToCity["Bogota"] = City::Bogota;
        this->stringToCity["Lima"] = City::Lima;
        this->stringToCity["Santiago"] = City::Santiago;
        this->stringToCity["BuenosAires"] = City::BuenosAires;
        this->stringToCity["SaoPaulo"] = City::SaoPaulo;
        this->stringToCity["Lagos"] = City::Lagos;
        this->stringToCity["Khartoum"] = City::Khartoum;
        this->stringToCity["Kinshasa"] = City::Kinshasa;
        this->stringToCity["Johannesburg"] = City::Johannesburg;

        this->stringToCity["Moscow"] = City::Moscow;
        this->stringToCity["Istanbul"] = City::Istanbul;
        this->stringToCity["Algiers"] = City::Algiers;
        this->stringToCity["Cairo"] = City::Cairo;
        this->stringToCity["Baghdad"] = City::Baghdad;
        this->stringToCity["Tehran"] = City::Tehran;
        this->stringToCity["Delhi"] = City::Delhi;
        this->stringToCity["Riyadh"] = City::Riyadh;
        this->stringToCity["Karachi"] = City::Karachi;
        this->stringToCity["Kolkata"] = City::Kolkata;
        this->stringToCity["Mumbai"] = City::Mumbai;
        this->stringToCity["Chennai"] = City::Chennai;

        this->stringToCity["Beijing"] = City::Beijing;
        this->stringToCity["Shanghai"] = City::Shanghai;
        this->stringToCity["Seoul"] = City::Seoul;
        this->stringToCity["Tokyo"] = City::Tokyo;
        this->stringToCity["Osaka"] = City::Osaka;
        this->stringToCity["Taipei"] = City::Taipei;
        this->stringToCity["HongKong"] = City::HongKong;
        this->stringToCity["Bangkok"] = City::Bangkok;
        this->stringToCity["Manila"] = City::Manila;
        this->stringToCity["Jakarta"] = City::Jakarta;
        this->stringToCity["HoChiMinhCity"] = City::HoChiMinhCity;
        this->stringToCity["Sydney"] = City::Sydney;        

        //Mapping the colors to string
        this->stringToColor["Blue"] = Color::Blue;
        this->stringToColor["Red"] = Color::Red;
        this->stringToColor["Yellow"] = Color::Yellow;
        this->stringToColor["Black"] = Color::Black;


        this->colorToCure.insert(make_pair(Color::Black, false));
        this->colorToCure.insert(make_pair(Color::Blue, false));
        this->colorToCure.insert(make_pair(Color::Red, false));
        this->colorToCure.insert(make_pair(Color::Yellow, false));




    }
    Board::Board(){
        initMaps();

        string line;
        ifstream myfile ("cities_map.txt");
        //Reading the citiesmap file 
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {
                
                string word = "";
                int counter = 0;
                string city;
                string color;
                list<string> listOfConnetive;

                for (auto x : line) 
                {
                    if (x == ' ')
                    {
                        counter+=1;
                        if(counter==1){
                            city=word;
                            this->cards.insert(this->stringToCity[city]);
                            cityToResearch.insert(make_pair(this->stringToCity[city], false));
                        }
                        else if(counter==2){
                            color=word;
                        }
                        else{
                            listOfConnetive.push_back(word);
                        }
                        word="";
                    }
                    else {
                        word = word + x;
                    }
                }
                listOfConnetive.push_back(word);

                for (string cityConnect : listOfConnetive){
                    this->cityConnectionMap[this->stringToCity[city]].push_back(this->stringToCity[cityConnect]);
                }
                this->cityColorMap[this->stringToCity[city]] = this->stringToColor[color];
            }
            myfile.close();
        }
    }
}