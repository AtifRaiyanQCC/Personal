#include "Iterator.h"

Iterator::Iterator(Node *n): current(n) {       
}
void Iterator::next() {            //goes to the next data point        
    current = current->next;
}
void Iterator::prev() {            // goes to the previous data point
    current = current->prev;
}
bool Iterator::hasNext() {         // checks if current data is not null
    if(current != nullptr) { 
        return true; 
    } else {
        return false;
    }
}
bool Iterator::hasPrev() {         // checks if current data is not null
    if(current != nullptr) { 
        return true; 
    } else {
        return false;
    }
}    
Profession& Iterator::getData() {   // gets specified data
    return current->data;
}