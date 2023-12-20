#include <iostream>
#include <fstream>
#include <sstream>
#include "Contestant.h"
#include "Coordinator.h"
#include "Race.h"
#include "Files.h"


int main() {
    std::vector<Contestant*> contestants;
    std::vector<Race*> races;

    std::vector<Contestant*>::iterator contestantIterator;
    std::vector<Race*>::iterator raceIterator;

    //files.h
    readContestant(contestants);
    readRace(races);
    std::cout << "Contestants:\n";
    print(contestants);

    std::cout << "\nRaces:\n";
    print(races);

    
    for (std::vector<Contestant*>::size_type i = 0; i < contestants.size(); ++i) {
        std::vector<Race*>::size_type racesAssigned = 0; 
        for (std::vector<Race*>::size_type j = 0; j < races.size() && racesAssigned < contestants[i]->getMaxRaces(); ++j) {
            contestants[i]->addRace(races[j]);
            races[j]->addContestant(contestants[i]);
            ++racesAssigned;
        }
    }
    
    std::cout << "\nContestants and their eraces:\n";
    for (auto& contestants : contestants) {
        contestants->displayR();  
    }

    
    std::cout << "\nRace and its contestants:\n";
    for (auto& race : races) {
        race->displayC();  

    
    Coordinator coordinator;

    
    coordinator.createRace(races, "10 Mile");

    
    auto raceIt = coordinator.findRace(races, "6 Mile");
    if (raceIt != races.end()) {
        coordinator.removeRace(races, *raceIt);
    }

    
    std::cout << "\nUpdated Races:\n";
    print(races);

    clear(contestants);
    clear(races);

    return 0;
}
}