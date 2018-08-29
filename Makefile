default: rolls.o
	g++ -std=c++11 risk_sim.cpp rolls.o -o risk_sim
rolls.o: rolls.cpp
	g++ -std=c++11 -c rolls.cpp
