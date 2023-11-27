#include "Iterator.h"

Iterator::Iterator(Node *n): current(n) {
}
void Iterator::next() {
    current = current->next;
}
void Iterator::prev() {
    current = current->prev;
}
bool Iterator::hasNext() {
    if(current != nullptr) { 
        return true; 
    } else {
        return false;
    }
}
bool Iterator::hasPrev() {
    if(current != nullptr) { 
        return true; 
    } else {
        return false;
    }
}    
Profession& Iterator::getData() {
    return current->data;
}