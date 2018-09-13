#include <iostream>
#include "game_simulator.h" 

/* getters and setters */

void GameSimulator::set_num_attacker_dice(int attacker_dice) {
  this->num_attacker_dice = attacker_dice;
}

void GameSimulator::set_num_defender_dice(int defender_dice) {
  this->num_defender_dice = defender_dice;
}

const int GameSimulator::get_num_attacker_dice() {
  return this->num_attacker_dice;
}

const int GameSimulator::get_num_defender_dice() {
  return this->num_defender_dice;
}

const int GameSimulator::get_attacker_wins() {
  return this->num_attacker_wins;
}

const int GameSimulator::get_defender_wins() {
  return this->num_defender_wins;
}

/* end getters and setters */

GameSimulator::GameSimulator() {
  this->num_defender_wins = 0;
  this->num_attacker_wins = 0;
}


void GameSimulator::run_games(int num_games) {
  this->num_attacker_wins = 0;
  this->num_defender_wins = 0;
  for (int i = 0; i < num_games; i++)
    this->run_game();  
}

void GameSimulator::run_game() {
  this->attacker_rolls = Rolls(this->num_attacker_dice);
  this->defender_rolls = Rolls(this->num_defender_dice);
  this->calculate_win(this->attacker_rolls.First(), this->defender_rolls.First());
  this->calculate_win(this->attacker_rolls.Second(), this->defender_rolls.Second());
}

void GameSimulator::calculate_win(int attacker_rolls, int defender_rolls) {
  if (attacker_rolls > defender_rolls)
    this->num_attacker_wins++;
  else
    this->num_defender_wins++;
}
