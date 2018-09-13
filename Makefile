default: rolls.o game_simulator.o
	g++ -std=c++17 main.cpp rolls.o game_simulator.o -o risk_sim
rolls.o: rolls.cpp
	g++ -std=c++17 -c rolls.cpp
game_simulator.o: game_simulator.cpp
	g++ -std=c++17 -c game_simulator.cpp
