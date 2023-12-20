#include "Contestant.h"


Contestant::Contestant() : name(name), id(0), maxRaces(0) {}   //Constructor
Contestant::Contestant(const std::string& name, int id, int maxRaces) : name(name), id(id), maxRaces(maxRaces) {}  //constructor with parameters
Contestant::~Contestant() {}    //deconstructor

std::string Contestant::getName() const {return name;}  //returns name
int Contestant::getId() const {return id;}  //returns id
int Contestant::getMaxRaces() const {return maxRaces;} //returns maxraces
std::vector<Race*> Contestant::getRaces() const {return races;} //returns races


int Contestant::getNumRaces() const {   //returns amount of data of races
    return races.size();
}
void Contestant::clear() {          //clears the races data
    for (auto& race : races) {
        race->removeContestant(this);
    }
    races.clear();
}
void Contestant::displayR() const { // displays the races under specific Contestant
    std::cout << "Contestant: " << name << " (ID: " << id << ")\n" << "Max Races: " << maxRaces << "\n";
    

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

void Contestant::setName(const std::string &newname) {name = newname;}  // sets a name
void Contestant::setId(int newid) {id = newid;}     //sets an id
void Contestant::setMaxRaces(int newMaxRaces) {maxRaces = newMaxRaces;} // sets maxraces
    

void Contestant::addRace(Race* race) {  //adds a race
    if (std::find(races.begin(), races.end(), race) == races.end()) {
        races.push_back(race);
    }
}

void Contestant::removeRace(Race* race) {       //removes a race
    auto it = std::find(races.begin(), races.end(), race);
    if (it != races.end()) {
        races.erase(it);
    }
}

bool Contestant::isMaxed() const {      //checks if it is maxed
    return races.size() >= maxRaces;
}
void Contestant::increaseMax() {        //increases max
    maxRaces++;
}
bool Contestant::operator==(const Contestant& other) const {                    //equality operator
    return (name == other.name && id == other.id && maxRaces == other.maxRaces);
}
std::ostream& operator<<(std::ostream& out, const Contestant& contestant) {     steam insertion operator
    out << "Name: " << contestant.name << ", ID: " << contestant.id << ", Max Races: " << contestant.maxRaces;
    return out;
}

