#ifndef NODE_H
#define NODE_H
#include <iostream>
#include <algorithm>
#include "Profession.h"

struct Node {
    Profession data ;   //makes a object of type Profession                                           
    Node *next;
    Node *prev;
    Node();
    Node(const Profession &d); 
};
#endif