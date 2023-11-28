#include <iostream>
#include <sstream>
#include <fstream>
#include "Node.h"
#include "List.h"
#include "Iterator.h"
#include "Algorithms.h"

void read(std::string file, List &list){
    std::ifstream Files;                            // creates file input object                               
    std::string cline, token;                       // creates  2 varibles to store data
    Files.open(file);                               // opens file called from main using parameter file
    while( getline(Files, cline) ){                 // while loop to parse every line in csv file
        std::istringstream parser(cline);           // connects stringstream object to line
        int Position = 0;                           // makes varaible Position
        std::string name;                           // varible to store data of name
        int number;                                 // varible to store data of number

        while( getline(parser, token, ',') ){       // while loop to seperate the line into tokens using ","
            if(Position == 0) {                     // If statement to cycle every row of the csv file
                name = token;
                ++Position;
            }
            else {                                  // coverter to convert string into integer
                std::istringstream converter(token);    
                converter >> number;                
                Position = 0;                       // sets Position to 0 to reset the cycle

            }
        }
        push_back(list, Profession(name, number));      // stores each read csv line to the end of a list 
        std::cout << name << " " << number << "\n";
    }
    Files.close();                                      // closes the file
}

int main() {
    std::cout << std::endl;

    List list; 
    list.clear();

    std::cout << "PUSH\n";
    push_front(list, Profession("N/A", 400));
    push_front(list, Profession("N/A", 200));  
    push_front(list, Profession("N/A", 100));
    push_back(list, Profession("N/A", 600));  
    push_back(list, Profession("N/A", 800)); 
    push_back(list, Profession("N/A", 1000));
    push_back(list, Profession("N/A", 1200));                                                                                                                  
    print(list); 
    printRev(list);

    std::cout << "\nPOP\n";
    pop_front(list);
    pop_back(list);
    pop_back(list);
    print(list);
    printRev(list);    

    Iterator itr = list.begin();                              // point an iterator to the list

    std::cout << "\nFIND/INSERT\n";
    itr = find(list, Profession("N/A", 200));
    insert(list, itr, Profession("N/A", 100));                                   // insert 100 before 200 (edge case)
    itr = find(list, Profession("N/A", 400));
    insert(list, itr, Profession("N/A", 300));                                   // insert 300 before 400   
    itr = find(list, Profession("N/A", 800));
    insert(list, itr, Profession("N/A", 700));                                   // insert 700 before 800     
    print(list);
    printRev(list);    

    std::cout << "\nFIND/ERASE\n";    
    itr = find(list, Profession("N/A", 200));
    erase(list, itr);                                         // erase 100, the node before 200 (edge case)
    itr = find(list, Profession("N/A", 800));
    erase(list, itr);                                         // erase 700, the node before 800     
    print(list);
    printRev(list);  
          

    std::cout << "\nCOPY\n"; 
    List list_copy;
    duplicate(list, list_copy);                             // duplicate list without sharing memory
    print(list);
    print(list_copy);                               

    std::cout << "\nMEMORY INDEPENDENCE\n";  
    list.~List();                                           // erase list
    print(list_copy);                                       // print copy

    std::cout << "\nList Size\n";
    std::cout << list.getSize() <<std::endl;

    std::cout << "\nALGORITHMS\n";
    list.clear();                               // set list to no values
    Algorithms alg;                             // object alg of type Algorithms
    List lists1, lists2;                        // object lists1 and lists2 of type List
    Profession d1("N/A", 100);                  // set data points to specific objects of type Profession          
    Profession d2("N/A", 300);
    Profession d3("N/A", 500);
    Profession d4("N/A", 700);
    Profession d5("N/A", 450);
    Profession d6("N/A", 550);
    Profession d7("N/A", 650);
    Profession d8("N/A", 750);

    push_back(lists1, d1);                      //calls objects and pushes them to the end of a list
    push_back(lists1, d2);
    push_back(lists1, d3);
    push_back(lists1, d4);
    push_back(lists2, d5);
    push_back(lists2, d6);
    push_back(lists2, d7);
    push_back(lists2, d8);

    print(lists1);                              // prints lists1
    print(lists2);                              // prints lists2
    alg.merge(lists1, lists2, list, true);      // calls member function merge with parameters lists1, lists2, list and true ie true means we want lower values
    print(list);                                
    std::cout << "\nmergeSort\n";
    alg.mergeSort(list, true);                  // calls member function mergesort with parameters list, true
    print(list);
    std::cout << "\nreverse\n";
    alg.reverse(list);                          // calls member function reverse with parameters list
    print(list);
    list.clear();                               // clears list
    

    std::cout << "\nCsv\n";
    read("data.csv", list);                     // read function being called with name of csv file
    std::cout << std::endl;
    print(list);
    
    std::cout << std::endl;
    return 0;
}
