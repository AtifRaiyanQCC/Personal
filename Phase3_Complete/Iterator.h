#ifndef ITERATOR_H
#define ITERATOR_H
#include <iostream>
#include <algorithm>
#include "Node.h"

struct Iterator {
    Node *current;
    Iterator(Node *n);
    void next();
    void prev();
    bool hasNext();
    bool hasPrev();
    Profession& getData();
};

#endif
