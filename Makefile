# Executable file to create and its dependencies
prog3: Contestant.o Coordinator.o Race.o driver_phase_3.o ContestantUI.o CoordinatorUI.o 
	g++ -std=c++11 -o prog3 Contestant.o Coordinator.o Race.o driver_phase_3.o ContestantUI.o CoordinatorUI.o 
prog2: Contestant.o Coordinator.o Race.o driver_phase_2.o
#	g++ -std=c++11 -o prog2 Contestant.o Coordinator.o Race.o driver_phase_2.o ContestantUI.o CoordinatorUI.o 
prog1: Contestant.o Coordinator.o Race.o driver_phase_1.o
#	g++ -std=c++11 -o prog1 Contestant.o Coordinator.o Race.o driver_phase_1.o

# File dependencies
Contestant.o: Contestant.cpp Contestant.h
	g++ -std=c++11 -c Contestant.cpp

Race.o: Race.cpp Race.h
	g++ -std=c++11 -c Race.cpp

Coordinator.o: Coordinator.cpp Coordinator.h
	g++ -std=c++11 -c Coordinator.cpp

ContestantUI.o: ContestantUI.cpp ContestantUI.h 
	g++ -std=c++11 -c ContestantUI.cpp

CoordinatorUI.o: CoordinatorUI.cpp CoordinatorUI.h
	g++ -std=c++11 -c CoordinatorUI.cpp
	
driver_phase_1.o: driver_phase_1.cpp Contestant.h Race.h Files.h
#	g++ -std=c++11 -c driver_phase_1.cpp

driver_phase_2.o: driver_phase_2.cpp Contestant.h Race.h Files.h Coordinator.h  
#	g++ -std=c++11 -c driver_phase_2.cpp

driver_phase_3.o: driver_phase_3.cpp Contestant.h Race.h Files.h Coordinator.h UserInterface.h CoordinatorUI.h ContestantUI.h 
	g++ -std=c++11 -c driver_phase_3.cpp

# Files to remove
clean:
	rm Contestant.o Coordinator.o Race.o driver_phase_3.o CoordinatorUI.o ContestantUI.o
	rm prog3
