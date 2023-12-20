#ifndef COORDINATORUI_H
#define COORDINATORUI_H

#include "UserInterface.h"

class CoordinatorUI : public UserInterface {
public:
    void menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) override;
    void createRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt, std::vector<Contestant*>& contestants, std::vector<Race*>& races);
    void deleteRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt, std::vector<Race*>& races);
};

#endif
