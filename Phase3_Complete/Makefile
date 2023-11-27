# executable file to create and its dependancies
prog : driver.o Node.o List.o Iterator.o Profession.o Algorithms.o
	g++ -std=c++11 -o prog driver.o Node.o List.o Iterator.o Profession.o Algorithms.o

# file dependencies
driver.o : Node.h List.h Iterator.h Algorithms.h
	g++ -std=c++11 -c driver.cpp
Node.o : Node.h Profession.h
	g++ -std=c++11 -c Node.cpp
List.o : Node.h List.h Iterator.h Profession.h
	g++ -std=c++11 -c List.cpp
Iterator.o : Node.h Iterator.h
	g++ -std=c++11 -c Iterator.cpp
Profession.o : Profession.h
	g++ -std=c++11 -c Profession.cpp
Algorithms.o : Node.h List.h Iterator.h Profession.h Algorithms.h
	g++ -std=c++11 -c Algorithms.cpp
# files to remove
clean:
	rm driver.o Node.o List.o Iterator.o Profession.o Algorithms.o
	rm prog