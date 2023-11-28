#include <iostream>
#include <string>
#include "Profession.h"

    Profession::Profession(): name("noname"), number(0){}

    Profession::Profession(std::string job, int emp) : name(job), number(emp) {}

void print(Profession &p){
    std::cout<< "Job: " << p.name << "\tNumber of employees: " << p.number << std::endl;        // format of print function
}

bool equivalent(Profession &p1, Profession &p2){
    if (p1.name == p2.name && p1.number == p2.number){              // function to check if values of the first data set is equivalent to the second data set
        return true;
    }
    else{
        return false;
    }
}

bool compare (Profession &p1,Profession &p2, bool less){        // compares if values of the first data set is lower when less is set to true and returns a bool result ie true or false
    if(less == true) {
        return p1.number <= p2.number;
    } else {
        return p1.number > p2.number;
    }
}