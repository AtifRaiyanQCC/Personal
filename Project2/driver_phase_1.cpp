#include <iostream>
#include <fstream>
#include <sstream>
#include "Contestant.h"
#include "Race.h"
#include "Files.h"

int main() {
    std::vector<Contestant*> contestants;
    std::vector<Race*> races;

    std::vector<Contestant*>::iterator contestantIterator;
    std::vector<Race*>::iterator raceIterator;

    readContestant(contestants);
    readRace(races);

    if (!contestants.empty() && !races.empty()) {
        contestants[0]->addRace(races[0]);
        races[0]->addContestant(contestants[0]);
    }

    if (!contestants.empty()) {
        std::cout << "\nContestant and their races:\n";
        std::cout << *contestants[0] << std::endl;
        contestants[0]->displayR();
    }

    if (!races.empty()) {
        std::cout << "\nRace and its contestants:\n";
        std::cout << *races[0] << std::endl;
        races[0]->displayC();
    }

    clear(contestants);
    clear(races);

    return 0;
}