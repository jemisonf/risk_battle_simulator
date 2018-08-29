#include <iostream>
#include <random>
#include <string>
#include <time.h>
#include <vector>

std::vector<int> run_game();
void init_rand();
int get_roll();
std::vector<int> get_rolls(int);

void init_rand() {
  srand(time(NULL));
}

int get_roll() {
  int roll = (rand() % 6) + 1;
  return roll;
}

std::vector<int> get_rolls(int num_rolls) {
  std::vector<int> rolls;
  for (int i = 0; i < num_rolls; i++) {
    rolls.push_back(get_roll());
    std::cout << std::to_string(rolls[i]) << " ";
    for (int j = 0; j < i; j++) {
      if (rolls[i] > rolls[j]) {
        int temp = rolls[i];
        rolls[i] = rolls[j];
        rolls[j] = temp;
      }
    }
  }
  std::endl(std::cout);
  for (int i = 0; i < num_rolls; i++)
    std::cout << std::to_string(rolls[i]) << " ";
  std::endl(std::cout);
  std::endl(std::cout);
  return rolls;
}

std::vector<int> run_game() {
  std::vector<int> attacker_rolls = get_rolls(3);
  std::vector<int> defender_rolls = get_rolls(2);
  int defender_wins = 0;
  int attacker_wins = 0;
  std::cout << std::to_string(attacker_rolls[0]) << "vs" << std::to_string(defender_rolls[0]) << std::endl;
  std::cout << std::to_string(attacker_rolls[1]) << "vs" << std::to_string(defender_rolls[1]) << std::endl;
  if (attacker_rolls[0] > defender_rolls[0])
    attacker_wins++;
  else
    defender_wins++;
  if (attacker_rolls[1] > defender_rolls[1])
    attacker_wins++;
  else
    defender_wins++;
  std::vector<int> results;
  results.push_back(attacker_wins);
  results.push_back(defender_wins);
  return results;
}

int main(int argc, char* argv[]) {
  std::vector<int> game_results;
  int attacker_wins = 0, defender_wins = 0;
  init_rand();
  for (int i = 0; i < 10000; i++) {
    game_results = run_game();
    attacker_wins += game_results[0];
    defender_wins += game_results[1];
  }
  std::cout << "=================================\nDefender wins: " << std::to_string(defender_wins) << "\nAttacker wins: " << std::to_string(attacker_wins) << std::endl;
}
