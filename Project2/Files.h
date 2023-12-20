#ifndef FILES_H
#define FILES_H

#include "Contestant.h"
#include "Race.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

void readContestant(std::vector<Contestant*>& contestants) {
    std::ifstream file("Contestant.csv");
    std::string cline, name, token;
    int id, maxRaces;

    while (getline(file, cline)) {
        std::istringstream parser(cline);
        int position = 0;
        
        while( getline(parser, token, ',') ){
            if(position == 0) {                                       // If statement to cycle every row of the csv file
                name = token;
                ++position;
            }
            else if(position == 1) {                                  // coverter to convert string into integer
                std::istringstream converter(token);    
                converter >> id;                
                ++position;                                           // sets Position to 0 to reset the cycle

            }
            else {                                                   // coverter to convert string into integer
                std::istringstream converter(token);    
                converter >> maxRaces;                
                position = 0;                                       // sets Position to 0 to reset the cycle

            }
        }   
        contestants.push_back(new Contestant(name, id, maxRaces));  //pushes back data
    }
    file.close();
};




void readRace(std::vector<Race*>& races) {
    std::ifstream file("Race.csv");
    std::string cline, name;
    

    while (getline(file, cline)) {
        std::istringstream parser(cline);
        getline(parser, name, ',');
        races.push_back(new Race(name));
    }
}

template<typename T>
void print(const std::vector<T*>& container) {
    for (const auto& item : container) {
        std::cout << *item << std::endl;
    }
}

template<typename T>
void clear(std::vector<T*>& container) {
    for (auto& item : container) {
        delete item;
    }
    container.clear();
}

#endif
