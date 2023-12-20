#ifndef RACE_H
#define RACE_H

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

class Contestant;

class Race {
private:
    std::string name;
    std::vector<Contestant*> contestants;

public:
    Race();
    Race(const std::string& newName);

    std::string getName() const;

    void setName(const std::string& newName);

    bool operator==(const Race& other) const;

    friend std::ostream& operator<<(std::ostream& out, const Race& race);

    void displayC() const;
    std::vector<Contestant*>& getContestants();
    int getNumContestants() const;
    void addContestant(Contestant* contestant);
    void removeContestant(Contestant* contestant);
};

#endif
