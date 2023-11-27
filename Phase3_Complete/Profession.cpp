#include <iostream>
#include <string>
#include "Profession.h"

    Profession::Profession(): name("noname"), number(0){}

    Profession::Profession(std::string job, int emp) : name(job), number(emp) {}

void print(Profession &p){
    std::cout<< "Job: " << p.name << "\tNumber of employees: " << p.number << std::endl;
}

bool equivalent(Profession &p1, Profession &p2){
    if (p1.name == p2.name && p1.number == p2.number){
        return true;
    }
    else{
        return false;
    }
}

bool compare (Profession &p1,Profession &p2, bool less){
    if(less == true) {
        return p1.number <= p2.number;
    } else {
        return p1.number > p2.number;
    }
}