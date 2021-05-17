#pragma once
#include <stdexcept>
#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
#include <list>
#include <unordered_set>

using namespace std;

namespace pandemic{
    class Board{
        public:
            static const int NunOfCards=5;
            //City to list of cities
            map<City, int> cityToPandemic;

            //City to color mapping 
            map<City, Color> cityColorMap;

            //City to list of cities
            map<City, list<City>> cityConnectionMap;
            
            //Map string to city
            map<string, City> stringToCity;

            //String to color map
            map<string, Color> stringToColor;

            //Stack of cards
            unordered_set<City> cards;

            //Map of reachers facilitis
            map<City, bool> cityToResearch;

            //Map of reachers facilitis
            map<Color, bool> colorToCure;


            
            //Return the number of pandemic in giveen city
            int& operator[] (City city){
                return cityToPandemic[city];
            }
            //Constructor
            Board();
            
            //Enum to string
            string enumToString(const City city);
            string enumToStringColor(const Color color);

            //Operator << for osstream
            friend std::ostream& operator<< (std::ostream& os, const Board& n);

            //Init the maps
            void initMaps();

            //Cleaning functions
            bool is_clean();

            void remove_cures();

            void remove_stations();

    };
}