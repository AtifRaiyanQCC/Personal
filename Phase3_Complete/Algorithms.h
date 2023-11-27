#ifndef ALGORITHMS_H
#define ALGORITHMS_H
#include <iostream>
#include <algorithm>
#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include "Profession.h"

struct Algorithms{
void merge(List &s1, List &s2, List &list, bool less);
void mergeSort(List &list, bool less);
void reverse(List &list);
};

#endif