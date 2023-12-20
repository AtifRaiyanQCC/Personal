#include "Coordinator.h"

std::vector<Race*>::iterator Coordinator::findRace(std::vector<Race*>& races, const std::string& raceName) {
    return std::find_if(races.begin(), races.end(), [&raceName](const Race* race) {
        return race->getName() == raceName;
    });
}

void Coordinator::createRace(std::vector<Race*>& races, const std::string& name) {
    races.push_back(new Race(name));
}

void Coordinator::removeRace(std::vector<Race*>& races, Race* race) {
    if (race != nullptr) {

        for (auto& contestant : race->getContestants()) {
            contestant->removeRace(race);
        }

        races.erase(std::remove(races.begin(), races.end(), race), races.end());
        delete race;
    }
}
