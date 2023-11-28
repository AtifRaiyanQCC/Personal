#include "Node.h"

Node::Node(): data(Profession()), next(nullptr), prev(nullptr) {}                      
Node::Node(const Profession &d): data(d), next(nullptr), prev(nullptr) {};            

//makes a object of type Profession, makes node objects next and prev
