#include "Race.h"
#include "Contestant.h"

Race::Race() : name(""), contestants() {}
Race::Race(const std::string& newName) : name(newName), contestants() {}

int Race::getNumContestants() const {
    return contestants.size();
}
void Race::displayC() const {
    std::cout << "Race: " << name << "\n";
    if (!contestants.empty()) {
        std::cout << "Contestants:\n";
        for (const auto& contestant : contestants) {
            std::cout << "- " << contestant->getName() << "\n";
        }
    } else {
        std::cout << "No contestants scheduled.\n";
    }
    std::cout << "\n";
}

std::string Race::getName() const {return name;}
void Race::setName(const std::string& newName) {name = newName;}

bool Race::operator==(const Race& other) const {
    return name == other.name;
}
std::ostream& operator<<(std::ostream& out, const Race& race) {
    out << "Race: " << race.name;
    return out;
}

std::vector<Contestant*>& Race::getContestants() {
    return contestants;
}
void Race::addContestant(Contestant* contestant) {
    if (std::find(contestants.begin(), contestants.end(), contestant) == contestants.end()) {
        contestants.push_back(contestant);
    }
}
void Race::removeContestant(Contestant* contestant) {
    auto it = std::find(contestants.begin(), contestants.end(), contestant);
    if (it != contestants.end()) {
        contestants.erase(it);
    }
}
