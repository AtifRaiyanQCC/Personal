#include "CoordinatorUI.h"

void CoordinatorUI::menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) {
    char pl;
    do{
        std::cout << "\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n";
        std::cout << "Coordinator Menu:" << std::endl;
        std::cout << "A - Display all Races" << std::endl;
        std::cout << "B - Display all Contestants." << std::endl;
        std::cout << "C - Add Race." << std::endl;
        std::cout << "D - Remove Race." << std::endl;
        std::cout << "E - Race and its Contestants." << std::endl;
        std::cout << "F - Exit" << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n";
    
        std::cout << "Enter Cooresponding Letter: ";
        std::cin >> pl;

        switch (pl) {
            case 'A':
                UserInterface::display(races);
                break;
            case 'B':
                UserInterface::display(contestants);
                break;
            case 'C':
                createRace(contestants.begin(), races.begin(), contestants, races);
                break;
            case 'D':
                deleteRace(contestants.begin(), races.begin(), races);
                break;
            case 'E':
                {
                    auto racesIt = UserInterface::selectRace(races);
                    if(racesIt != races.end()) {
                        (*racesIt)->displayC();
                    }
                }
                break;
            case 'F':
                break; 
            default:
                std::cout << "Invalid Option. Try again" << std::endl;
        }
    }while(pl != 'F');
}

void CoordinatorUI::createRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt, std::vector<Contestant*>& contestants, std::vector<Race*>& races) {
    std::cout << "Create a Race:\n";
    std::string newRace;
    std::cin >> newRace;

    Coordinator cc;
    cc.createRace(races, newRace);
    racesIt = cc.findRace(races, newRace); 

    std::cout << "Select a Contestant:\n";
    contestantsIt = UserInterface::selectContestant(contestants);

    if (racesIt != races.end() && contestantsIt != contestants.end()) {
        (*contestantsIt)->addRace(*racesIt);
    }
}

void CoordinatorUI::deleteRace(std::vector<Contestant*>::iterator contestantsIt, std::vector<Race*>::iterator racesIt, std::vector<Race*>& races) {
    Coordinator cc;
    if (racesIt != races.end()) {
        (*contestantsIt)->removeRace(*racesIt);
        races.erase(racesIt);
        std::cout << "Race removed successfully.\n";
    } else {
        std::cout << "Race not found.\n";
    }
}




