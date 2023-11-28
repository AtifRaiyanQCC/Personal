#include "List.h"

                                              
List::List(): head(nullptr), tail(nullptr) {}
List::~List()
{
    Node *temp = head;
    Node *next;
    while(temp != nullptr) {
        next = temp;
        temp = temp->next;
        delete next;
    }
    head = tail = nullptr;        
}
int List::getSize(){                //int object size from h file
    return size;
}
void List::clear(){                 // defines when to set size to 0
    while(head != nullptr) {
        pop_front(*this); 
    }
    size = 0;
}
Iterator List::begin() {                // pushes first data point
    return Iterator(head);
} 
Iterator List::end() {                  // finds null
    return Iterator(nullptr);
}
Iterator List::rbegin() {               // pushes last data point 
    return Iterator(tail);
}                    
Iterator List::rend() {                 // finds null
    return Iterator(nullptr);
}
void push_front(List &list, const Profession &d)             // pushes lastest value to first data point   ie push_front(list, 400)   push_front(list, 200)
{                                                            // 400  -> 200 , 400
    Node *temp = new Node(d);
    if(list.head == nullptr) {
       list.tail = temp;
    } else {
        temp->next = list.head; 
        list.head->prev = temp; 
    }             
    list.head = temp; 
    list.size++;                           
}
void push_back(List &list, const Profession &d)               // pushes lastest value to last data point   ie push_back(list, 500)   push_back(list, 600)     
{                                                             // 200 , 400 , 500  -> 200 , 400 , 500 , 600
    if(list.head == nullptr) {                     
        push_front(list, d);
        return;
    }
    Node *temp = new Node(d);                                                           
    list.tail->next = temp;                                               
    temp->prev = list.tail;                                     
    list.tail = temp;
    list.size++;                                      
}
void pop_front(List &list) {                                // removes first data point   ie pop_front(list)   pop_front(list)
    if(list.head == nullptr) { return; }                    // 200 , 400 , 500 , 600 -> 500 , 600
    Node *temp = list.head;                                 
    list.head = list.head->next; 
    list.size--;                           
    delete temp;                                            
    if(list.head != nullptr) {                              
        list.head->prev = nullptr;                          
    } else {                                                
        list.tail = nullptr;                                 
    }
}
void pop_back(List &list) {                                 // removes last data point   ie pop_backt(list)   pop_back(list)
    if(list.tail == nullptr) { return; }                    // 500 , 600 -> 500 -> null
    if(list.tail == list.head) {                            
        pop_front(list);
        return;
    }
    Node *temp = list.tail;                                 
    list.tail = list.tail->prev;                             
    list.tail->next = nullptr;   
    list.size--;                          
    delete temp;                                            
}
Iterator insert(List &list, Iterator itr, const Profession &d)     // adds data point before the current address ie insert(list, itr, Profession("N/A", 100));
{                                                                  // 500 -> 100, 500
    if(itr.current == nullptr) { return itr; }             
    if(list.head == nullptr || itr.current == list.head) {          
        push_front(list, d);
        return list.begin();
    }
    Node *temp = new Node(d);                             
    temp->next = itr.current;                              
    temp->prev = itr.current->prev;
    itr.current->prev->next = temp; 
    itr.current->prev = temp;
    list.size++;
    return Iterator(temp);
}
Iterator erase(List &list, Iterator itr)                           // removes data point before the current address ie erase(list, itr);
{                                                                  // 100, 500 -> 500
    if(itr.current == nullptr) { return itr; }              
    if(list.head == nullptr || itr.current == list.head ) { return itr; } 
    if(list.head == itr.current->prev) {                   
        pop_front(list);
        return list.begin(); 
    }                              
    Node *temp = itr.current->prev;                         
    itr.current->prev = temp->prev;                         
    temp->prev->next = itr.current; 
    list.size--;                        
    delete temp;                                         
    return itr;                                      
}
void duplicate(List &a, List &b)                                            // takes a list and copies it to another 
{
    Iterator itr = a.begin();
    while( itr.hasNext() ) {
        push_back(b, itr.getData());    
        itr.next();  
    }   
}
void print(List &list) {                                                        //prints list in a set format of Profession , number
    for(Iterator itr=list.begin(); itr.hasNext(); itr.next()) {
        print(itr.getData());
    }  
    std::cout << "\n";
}
void printRev(List &list) {                                                     //prints list backwards in a set format of Profession , number
    Iterator itr = list.rbegin();
    while(itr.hasPrev()) {
        print(itr.getData());  
        itr.prev();  
    }  
    std::cout << "\n";   
}
Iterator find(List &list, Profession d)                                          // sets current value to desired value  ie itr = find(list, Profession("N/A", 200));
{                                                                                // returns address of where 200 is stored
    Iterator itr = list.begin();
    while( itr.hasNext() ) {
        if( equivalent(itr.getData(),d)) { return itr; }
        itr.next();
    }   
    return Iterator(nullptr);     
}