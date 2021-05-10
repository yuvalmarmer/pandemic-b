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
            bool is_clean(){
                for (map<City, int>::iterator it = cityToPandemic.begin(); it != cityToPandemic.end(); ++it)
                {
                    if(it->second>0){
                        return false;
                    }
                }
                return true;
            };

            void remove_cures(){
                this->colorToCure.clear();
            };

            void remove_stations(){
                for (map<City, bool>::iterator it = cityToResearch.begin(); it != cityToResearch.end(); ++it)
                {
                    it->second = false;
                }
            }

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

            int operator[] (City city) const {
                return -1;
            }
            
            Board();
            friend std::ostream& operator<< (std::ostream& os, const Board& n);


            void initMaps();

    };
}