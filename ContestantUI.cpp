#include "ContestantUI.h"

void ContestantUI::menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) {
    std::vector<Contestant*>::iterator sc = contestants.end();
    char pl;
    do {
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Contestant Menu:" << std::endl;
        std::cout << "A - Display all Races" << std::endl;
        std::cout << "B - Contestant Selection" << std::endl;
        std::cout << "C - Display Race" << std::endl;
        std::cout << "D - Add Race" << std::endl;
        std::cout << "E - Remove Race" << std::endl;
        std::cout << "F - Exit" << std::endl;
        std::cout << "Pick Cooresponding Letter: ";
        std::cin >> pl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";

        switch (pl) {
            case 'A':
                UserInterface::display(races);
                break;
            case 'B':
                sc = UserInterface::selectContestant(contestants);
                break;
            case 'C':
                if(sc != contestants.end()) {
                    (*sc)->displayR();
                }
                break;
            case 'D':
                if(sc != contestants.end()) {
                        addRace(sc, races.begin(), races);
                    }
                break;
            case 'E':
                if(sc != contestants.end()) {
                        removeRace(sc, races.begin());
                    }
                break;
            case 'F':
                break;
            default:
                std::cout << "Invalid Option. Try again" << std::endl;
        }
    }while(pl != 'F');
}

void ContestantUI::addRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt, std::vector<Race*>& races) {
    auto raceIt = UserInterface::selectRace(races);
    if(raceIt != races.end()) {
        (*contestantsIt)->addRace(*raceIt);
        std::cout << "Race added successfully.\n";
    }
}

void ContestantUI::removeRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt) {
    (*contestantsIt)->removeRace(*racesIt);
    std::cout << "Race removed successfully.\n";
}
