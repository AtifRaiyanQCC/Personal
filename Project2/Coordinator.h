#ifndef COORDINATOR_H
#define COORDINATOR_H

#include "Race.h"
#include "Contestant.h"
#include <vector>

class Coordinator {
public:
    static std::vector<Race*>::iterator findRace(std::vector<Race*>& races, const std::string& raceName);

    static void createRace(std::vector<Race*>& races, const std::string& name);

    static void removeRace(std::vector<Race*>& races, Race* race);
};

#endif