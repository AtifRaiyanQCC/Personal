#ifndef PROFESSION_H
#define PROFESSION_H

#include <iostream>
#include <string>

struct Profession {
    int number;
    std::string name;

    Profession();
    Profession(std::string job, int emp);
};

void print(Profession &p);
bool equivalent(Profession& p1, Profession& p2);
bool compare(Profession& p1, Profession& p2, bool less);

#endif