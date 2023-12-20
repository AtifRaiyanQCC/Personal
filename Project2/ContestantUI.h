#ifndef CONTESTANTUI_H
#define CONTESTANTUI_H

#include "UserInterface.h"  
   

class ContestantUI : public UserInterface {
public:
    void menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) override;   
    static void addRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator raceIt, std::vector<Race*>& races);
    static void removeRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt);
};

#endif
