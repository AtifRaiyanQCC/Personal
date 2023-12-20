#ifndef CONTESTANT_H
#define CONTESTANT_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include "Race.h"

class Race;

class Contestant {
private:
    std::string name;
    int id;
    int maxRaces;
    std::vector<Race*> races;
public:
    Contestant();
    Contestant(const std::string& name, int id, int maxRaces);
    ~Contestant();

    std::string getName() const;
    int getId() const;
    int getMaxRaces() const;
    std::vector<Race*> getRaces() const;
    

    int getNumRaces() const;
    void clear();
    void displayR() const;

    void setName(const std::string& name);
    void setId(int id);
    void setMaxRaces(int maxRaces);
    void addRace(Race* race);
    void removeRace(Race* race);
    bool isMaxed() const;
    void increaseMax();


    bool operator==(const Contestant& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Contestant& contestant);
    
};

#endif
