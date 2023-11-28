#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include <algorithm>
#include "Node.h"

struct Iterator {
    Node *current;                      //makes object current of type Node
    Iterator(Node *n);
    void next();
    void prev();
    bool hasNext();
    bool hasPrev();
    Profession& getData();
};

#endif
