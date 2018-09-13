#include <iostream>
#include <random>
#include "rolls.h"

void Rolls::swap_rolls(int inner_roll_idx, int outer_roll_idx) {
  int temp = this->roll_values.at(outer_roll_idx);
  this->roll_values.at(outer_roll_idx) = this->roll_values.at(inner_roll_idx);
  this->roll_values.at(inner_roll_idx) = temp;
}

int Rolls::get_roll() {
  int roll = (rand() % 6) + 1;
  return roll;
}

void Rolls::sort() {
  for (int i = 0; i < this->roll_values.size(); i++) {
    for (int j = i; j < this->roll_values.size(); j++) {
      if (this->roll_values.at(i) < this->roll_values.at(j)) {
        this->swap_rolls(i, j);
      }
    }
  }
}


void Rolls::generate_rolls() {
  for (int& roll : this->roll_values) {
    roll = this->get_roll();
  }
}

Rolls::Rolls(int num_rolls) {
  this->roll_values = std::vector<int>(num_rolls);
  this->generate_rolls();
  this->sort();
}

Rolls::Rolls() {
  this->roll_values = std::vector<int>(0); 
}

Rolls::Rolls(const Rolls & new_rolls) {
  this->copy(new_rolls);
}

void Rolls::operator=(const Rolls & new_rolls) {
  this->copy(new_rolls);
}

void Rolls::copy(const Rolls & new_rolls) {
  this->roll_values = std::vector<int>(new_rolls.roll_values);
}

int Rolls::First() {
  return this->roll_values[0];
}

int Rolls::Second() {
  return this->roll_values[1];
}


