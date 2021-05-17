#include "Board.hpp"
#include <iostream>
#include <fstream>
#include <string>
#include <utility>      

using namespace std;
namespace pandemic{
    //enumToString
    string enumToStringCity(const City city){
        switch (city)
        {
        case City::SanFrancisco :
            return "SanFrancisco";
            break;
        case City::Chicago :
            return "Chicago";
            break;    
        case City::Montreal :
            return "Montreal";
            break; 
        case City::NewYork :
            return "NewYork";
            break; 
        case City::Atlanta :
            return "Atlanta";
            break; 
        case City::Washington :
            return "Washington";
            break;
            case City::Madrid :
            return "Madrid";
            break;
        case City::London :
            return "London";
            break;    
        case City::Essen :
            return "Essen";
            break; 
        case City::Milan :
            return "Milan";
            break; 
        case City::Paris :
            return "Paris";
            break; 
        case City::StPetersburg :
            return "StPetersburg";
            break;             
        
        
        
        case City::LosAngeles :
            return "LosAngeles";
            break;
        case City::MexicoCity :
            return "MexicoCity";
            break;    
        case City::Miami :
            return "Miami";
            break; 
        case City::Bogota :
            return "Bogota";
            break; 
        case City::Lima :
            return "Lima";
            break; 
        case City::Santiago :
            return "Santiago";
            break;
            case City::BuenosAires :
            return "BuenosAires";
            break;
        case City::SaoPaulo :
            return "SaoPaulo";
            break;    
        case City::Lagos :
            return "Lagos";
            break; 
        case City::Khartoum :
            return "Khartoum";
            break; 
        case City::Kinshasa :
            return "Kinshasa";
            break; 
        case City::Johannesburg :
            return "Johannesburg";
            break;  
        
        
        case City::Moscow :
            return "Moscow";
            break;
        case City::Istanbul:
            return "Istanbul";
            break;    
        case City::Algiers :
            return "Algiers";
            break; 
        case City::Cairo :
            return "Cairo";
            break; 
        case City::Baghdad :
            return "Baghdad";
            break; 
        case City::Tehran :
            return "Tehran";
            break;
            case City::Delhi :
            return "Delhi";
            break;
        case City::Riyadh :
            return "Riyadh";
            break;    
        case City::Karachi :
            return "Karachi";
            break; 
        case City::Kolkata :
            return "Kolkata";
            break; 
        case City::Mumbai :
            return "Mumbai";
            break; 
        case City::Chennai :
            return "Chennai";
            break;  
        

        case City::Beijing :
            return "Beijing";
            break;
        case City::Shanghai :
            return "Shanghai";
            break;    
        case City::Seoul :
            return "Seoul";
            break; 
        case City::Tokyo :
            return "Tokyo";
            break; 
        case City::Osaka :
            return "Osaka";
            break; 
        case City::Taipei :
            return "Taipei";
            break;
        case City::HongKong :
            return "HongKong";
            break;
        case City::Bangkok :
            return "Bangkok";
            break;    
        case City::Manila :
            return "Manila";
            break; 
        case City::Jakarta :
            return "Jakarta";
            break; 
        case City::HoChiMinhCity :
            return "HoChiMinhCity";
            break; 
        case City::Sydney :
            return "Sydney";
            break;  
        
        
        
        default:
            return "NO SUCH CITY";
            break;
        }
        
    }
    
    //enumToString
    string enumToStringColor(const Color color){
        switch (color)
        {
        case Color::Black:
            return "Black";
            break;
        case Color::Blue:
            return "Blue";
            break;
        case Color::Red:
            return "Red";
            break;
        case Color::Yellow:
            return "Yellow";
            break;
        default:
            return "Color dosnt exists";
            break;
        }
    }
    
    //Operator from draw the board
    ostream& operator<< (ostream& os, const Board& n){
        
        cout << "---------------Cures---------------" << endl;
        //Print all cures that founded
        for (map<Color, bool>::const_iterator it = n.colorToCure.begin(); it != n.colorToCure.end(); ++it)
        {
            if(it->second){
                // Color c = it->first;
                string color = enumToStringColor(it->first);
                cout << "The color " << color  << " has a cure!" << endl;
            }
        }
        cout << "---------Research facilitys--------" << endl;

        // //Print all research facilitys 
        for (map<City, bool>::const_iterator it = n.cityToResearch.begin(); it != n.cityToResearch.end(); ++it)
        {
            if(it->second){
                string city = enumToStringCity(it->first);
                cout << "The city " << city  << " has a research facility!" << endl;

            }
        }

        cout << "---------------Cities---------------" << endl;

        // //Print pandemic of each city
        for (map<City, int>::const_iterator it = n.cityToPandemic.begin(); it != n.cityToPandemic.end(); ++it)
        {
            if(it->second>0){
                string city = enumToStringCity(it->first);
                cout << "The city " << city  << " has a pandemic " <<  it->second <<endl;
            }
        }
        // return true;
        return os;
    }

    //Init the board
    void Board::initMaps(){
        //Init the string to City map 
        //----------------------------------------
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
        //----------------------------------------

        //Mapping the colors to string
        //----------------------------------------
        this->stringToColor["Blue"] = Color::Blue;
        this->stringToColor["Red"] = Color::Red;
        this->stringToColor["Yellow"] = Color::Yellow;
        this->stringToColor["Black"] = Color::Black;
        //----------------------------------------

        //init the color to cure map the be false
        //----------------------------------------
        this->colorToCure.insert(make_pair(Color::Black, false));
        this->colorToCure.insert(make_pair(Color::Blue, false));
        this->colorToCure.insert(make_pair(Color::Red, false));
        this->colorToCure.insert(make_pair(Color::Yellow, false));
        //----------------------------------------
    }
    
    //Constructor of the board
    Board::Board(){
        //Init the maps 
        initMaps();

        string line;
        ifstream myfile ("cities_map.txt");

        //Reading the citiesmap file 
        if (myfile.is_open())
        {
            while ( getline (myfile,line) )
            {   
                string word;
                int counter = 0;
                string city;
                string color;
                list<string> listOfConnetive;
                //Breake the line into chars
                for (auto x : line) 
                {
                    if (x == ' ')
                    {
                        counter+=1;
                        //The first word is the main city
                        if(counter==1){     
                            city=word;
                            this->cards.insert(this->stringToCity[city]);
                            cityToResearch.insert(make_pair(this->stringToCity[city], false));
                        }
                        //The second word is the color word 
                        else if(counter==2){
                            color=word;
                        }
                        //Every else is the nighbors  
                        else{
                            listOfConnetive.push_back(word);
                        }
                        word="";
                    }
                    else {
                        word += x;
                        
                    }
                }
                listOfConnetive.push_back(word);

                //Build back the connectivity map from the list
                for (string const &cityConnect : listOfConnetive){
                    this->cityConnectionMap[this->stringToCity[city]].push_back(this->stringToCity[cityConnect]);
                }
                //Coloring the city with given color
                this->cityColorMap[this->stringToCity[city]] = this->stringToColor[color];
            }
            myfile.close();
        }
    }

    //Checks if the board is clean from pandemic
    bool Board::is_clean(){
        for (map<City, int>::iterator it = cityToPandemic.begin(); it != cityToPandemic.end(); ++it)
        {
            if(it->second>0){
                return false;
            }
        }
        return true;
    };

    //Remove all cures from the the game
    void Board::remove_cures(){
        this->colorToCure.clear();
    };

    //Remove all research facilities from game
    void Board::remove_stations(){
        for (map<City, bool>::iterator it = cityToResearch.begin(); it != cityToResearch.end(); ++it)
        {
            it->second = false;
        }
    }


}