#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Coordinator.h"
#include "Contestant.h"
#include "Race.h"
#include <vector>
#include <iostream>

class UserInterface {
public:
    virtual void menu(std::vector<Contestant*>& contestants, std::vector<Race*>& races) = 0;

    template<typename T>
    static void display(const std::vector<T*>& container) {
        for (const auto& item : container) {
            std::cout << *item << std::endl;
        }
    }

    static std::vector<Contestant*>::iterator selectContestant(std::vector<Contestant*>& contestants) {
        std::vector<Contestant*>::size_type option;
        display(contestants);

        std::cout << "Select an Contestent by order - Enter Number: ";
        std::cin >> option;

        if (option > 0 && option <= contestants.size()) {
            return contestants.begin() + (option - 1);
        } else {
            return contestants.end();
        }
    }

    static std::vector<Race*>::iterator selectRace(std::vector<Race*>& races) {
        std::vector<Race*>::size_type option;
        display(races);

        std::cout << "Select an Race by order - Enter Number: ";
        std::cin >> option;

        if (option > 0 && option <= races.size()) {
            return races.begin() + (option - 1);
        } else {
            return races.end();
        }
    }
};

#endif
