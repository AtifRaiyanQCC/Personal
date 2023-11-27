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
int List::getSize(){
    return size;
}
void List::clear(){
    while(head != nullptr) {
        pop_front(*this); 
    }
    size = 0;
}
Iterator List::begin() {
    return Iterator(head);
} 
Iterator List::end() {
    return Iterator(nullptr);
}
Iterator List::rbegin() {
    return Iterator(tail);
}                    
Iterator List::rend() {
    return Iterator(nullptr);
}
void push_front(List &list, const Profession &d)                   
{
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
void push_back(List &list, const Profession &d)                    
{
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
void pop_front(List &list) {
    if(list.head == nullptr) { return; }                    
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
void pop_back(List &list) {
    if(list.tail == nullptr) { return; }                    
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
Iterator insert(List &list, Iterator itr, const Profession &d)     
{
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
Iterator erase(List &list, Iterator itr)          
{
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
void duplicate(List &a, List &b)
{
    Iterator itr = a.begin();
    while( itr.hasNext() ) {
        push_back(b, itr.getData());    
        itr.next();  
    }   
}
void print(List &list) {                              
    for(Iterator itr=list.begin(); itr.hasNext(); itr.next()) {
        print(itr.getData());
    }  
    std::cout << "\n";
}
void printRev(List &list) { 
    Iterator itr = list.rbegin();
    while(itr.hasPrev()) {
        print(itr.getData());  
        itr.prev();  
    }  
    std::cout << "\n";   
}
Iterator find(List &list, Profession d) 
{
    Iterator itr = list.begin();
    while( itr.hasNext() ) {
        if( equivalent(itr.getData(),d)) { return itr; }
        itr.next();
    }   
    return Iterator(nullptr);     
}