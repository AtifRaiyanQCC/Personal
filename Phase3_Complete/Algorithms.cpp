#include "Algorithms.h"

void Algorithms::merge(List &s1, List &s2, List &list, bool less){
    Iterator l1 = s1.begin();
    Iterator l2 = s2.begin();
    if (less == true){
        while (l1.hasNext() == true && l2.hasNext() == true){
            if (compare(l1.getData(), l2.getData(), less) == true){
                push_back(list, l1.getData());
                l1.next();
            }
            else if (compare(l1.getData(), l2.getData(), less) == false){
                push_back(list, l2.getData());
                l2.next();
            }
        }
        while (l1.hasNext() == true && l2.hasNext() == false) 
        {
            push_back(list, l1.getData());
            l1.next();
        }

        while (l1.hasNext() == false && l2.hasNext() == true) 
        {
            push_back(list, l2.getData());
            l2.next();
            
        }
    }
    else{
        while (l1.hasNext() == true && l2.hasNext() == true){
            if (compare(l1.getData(), l2.getData(), less) == false){
                push_front(list, l1.getData());
                l1.next();
            }
            else if (compare(l1.getData(), l2.getData(), less) == true){
                push_front(list, l2.getData());
                l2.next();
            }
        }
        while (l1.hasNext() == true && l2.hasNext() == false) 
        {
            push_front(list, l1.getData());
            l1.next();
        }

        while (l1.hasNext() == false && l2.hasNext() == true) 
        {
            push_front(list, l2.getData());
            l2.next();
            
        }
    }
}
void Algorithms::mergeSort(List &list, bool less){   
    int size = list.getSize();
    if (size <= 1) {
        return;
    }

    List subList1, subList2;
    Iterator temp = list.begin();
    for (int i = 0; i < size / 2; ++i) {
        push_back(subList1, temp.getData());
        temp.next();
    }

    while (temp.hasNext()) {
        push_back(subList2, temp.getData());
        temp.next();
    }

    list.clear();

    //mergeSort(subList1, less);
    //mergeSort(subList2, less);

    merge(subList1, subList2, list, less);
}

void Algorithms::reverse(List &list){
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

