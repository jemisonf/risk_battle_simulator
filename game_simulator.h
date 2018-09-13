#include "rolls.h"

class GameSimulator {
  public:
    GameSimulator();
    void set_num_attacker_dice(int);
    void set_num_defender_dice(int);
    const int get_num_attacker_dice();
    const int get_num_defender_dice();
    void run_games(int);
    const int get_attacker_wins();
    const int get_defender_wins();

  private:
    void run_game();
    void calculate_win(int, int);
    int num_games;
    int num_attacker_dice;
    int num_defender_dice;
    int num_defender_wins;
    int num_attacker_wins;
    Rolls attacker_rolls;
    Rolls defender_rolls;
};
