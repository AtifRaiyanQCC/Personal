#include "Algorithms.h"

void Algorithms::merge(List &s1, List &s2, List &list, bool less){
    Iterator l1 = s1.begin();               // makes object l1 of type Iterator
    Iterator l2 = s2.begin();               // makes object l2 of type Iterator
    if (less == true){                      // checks if we want lower values if less == true
        while (l1.hasNext() == true && l2.hasNext() == true){
            if (compare(l1.getData(), l2.getData(), less) == true){     
                push_back(list, l1.getData());                                // if true moves data of l1 to back of the list
                l1.next();
            }
            else if (compare(l1.getData(), l2.getData(), less) == false){
                push_back(list, l2.getData());                                // else moves data of l2 to back of the list
                l2.next();
            }
        }
        while (l1.hasNext() == true && l2.hasNext() == false)               // while l1 has values but l2 does not
        {
            push_back(list, l1.getData());
            l1.next();
        }

        while (l1.hasNext() == false && l2.hasNext() == true)           // while l2 has values but l1 does not
        {
            push_back(list, l2.getData());
            l2.next();
            
        }
    }
    else{   
        while (l1.hasNext() == true && l2.hasNext() == true){
            if (compare(l1.getData(), l2.getData(), less) == false){
                push_front(list, l1.getData());                         // if false moves data of l1 to front of the list
                l1.next();
            }
            else if (compare(l1.getData(), l2.getData(), less) == true){
                push_front(list, l2.getData());                         // else moves data of l2 to front of the list
                l2.next();
            }
        }
        while (l1.hasNext() == true && l2.hasNext() == false)       // while l1 has values but l2 does not
        {
            push_front(list, l1.getData());
            l1.next();
        }

        while (l1.hasNext() == false && l2.hasNext() == true)           // while l2 has values but l1 does not
        {
            push_front(list, l2.getData());
            l2.next();
            
        }
    }
}
void Algorithms::mergeSort(List &list, bool less){   
    int size = list.getSize();                      //checks size of the list so a list of one or less data, it can not get split in half
    if (size <= 1) {
        return;
    }

    List subList1, subList2;                        // creates object subList1, subList2 of type List
    Iterator temp = list.begin();                   // object named temp of type Iterator getting data from the initial list starting from the begining
    for (int i = 0; i < size / 2; ++i) {            // for loop to obtain the first half of the initial list to store in subList1
        push_back(subList1, temp.getData());
        temp.next();
    }

    while (temp.hasNext()) {                        // while loop to obtain remaining half of initial list to store in subList2
        push_back(subList2, temp.getData());
        temp.next();
    }

    list.clear();                                   //clears initial list

    //mergeSort(subList1, less);
    //mergeSort(subList2, less);

    merge(subList1, subList2, list, less);          // merges both sublists together
}

void Algorithms::reverse(List &list){               //duplicates list and reverses it
    Iterator met = list.begin();
    List el;
    el.clear();
    for (met; met.hasNext(); met.next()){
        push_back(el, met.getData());
    }
    list.clear();
    Iterator tem = el.begin();
    for (tem; tem.hasNext(); tem.next()){
        push_front(list, tem.getData());
    }
}

