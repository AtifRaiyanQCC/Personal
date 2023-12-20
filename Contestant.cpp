#include "Contestant.h"


Contestant::Contestant() : name(name), id(0), maxRaces(0) {}
Contestant::Contestant(const std::string& name, int id, int maxRaces) : name(name), id(id), maxRaces(maxRaces) {}
Contestant::~Contestant() {}

std::string Contestant::getName() const {return name;}
int Contestant::getId() const {return id;}
int Contestant::getMaxRaces() const {return maxRaces;}
std::vector<Race*> Contestant::getRaces() const {return races;}


int Contestant::getNumRaces() const {
    return races.size();
}
void Contestant::clear() {
    for (auto& race : races) {
        race->removeContestant(this);
    }
    races.clear();
}
void Contestant::displayR() const {
    std::cout << "Contestant: " << name << " (ID: " << id << ")\n" << "Max Races: " << maxRaces << "\n";;
    

    if (!races.empty()) {
        std::cout << "Races:\n";
        for (const auto& race : races) {
            std::cout << "- " << race->getName() << "\n";
        }
    } else {
        std::cout << "No races scheduled.\n";
    }

    std::cout << "\n";
}

void Contestant::setName(const std::string &newname) {name = newname;} 
void Contestant::setId(int newid) {id = newid;}
void Contestant::setMaxRaces(int newMaxRaces) {maxRaces = newMaxRaces;}
    

void Contestant::addRace(Race* race) {
    if (std::find(races.begin(), races.end(), race) == races.end()) {
        races.push_back(race);
    }
}

void Contestant::removeRace(Race* race) {
    auto it = std::find(races.begin(), races.end(), race);
    if (it != races.end()) {
        races.erase(it);
    }
}

bool Contestant::isMaxed() const {
    return races.size() >= maxRaces;
}
void Contestant::increaseMax() {
    maxRaces++;
}
bool Contestant::operator==(const Contestant& other) const {
    return (name == other.name && id == other.id && maxRaces == other.maxRaces);
}
std::ostream& operator<<(std::ostream& out, const Contestant& contestant) {
    out << "Name: " << contestant.name << ", ID: " << contestant.id << ", Max Races: " << contestant.maxRaces;
    return out;
}

