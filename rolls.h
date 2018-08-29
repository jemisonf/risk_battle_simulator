#include <vector>

using namespace std;
class Rolls {
  private: 
    std::vector<int> roll_values;
    int get_roll();
    void sort();
    void generate_rolls();
    void swap_rolls(int, int);
    

  public:
    Rolls(int);
    int First();
    int Second();
};
