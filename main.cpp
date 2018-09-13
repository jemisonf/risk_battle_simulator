#include <iostream>
#include <random>
#include <time.h>

#include "game_simulator.h"

int main(int argc, char* argv[]) {
  srand(time(NULL));
  int num_games = 1000;
  int num_attacker_dice = 3;
  int num_defender_dice = 2;
  GameSimulator game_sim = GameSimulator();
  game_sim.set_num_attacker_dice(num_attacker_dice);
  game_sim.set_num_defender_dice(num_defender_dice);
  game_sim.run_games(num_games);
  std::cout << "Num attacker wins: " << game_sim.get_attacker_wins() << std::endl;
  std::cout << "Num defender wins: " << game_sim.get_defender_wins() << std::endl;
}
