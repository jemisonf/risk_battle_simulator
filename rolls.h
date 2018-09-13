#include <vector>

using namespace std;
class Rolls {
  private: 
    std::vector<int> roll_values;
    int get_roll();
    void sort();
    void generate_rolls();
    void swap_rolls(int, int);
    void copy(const Rolls&);
    

  public:
    Rolls();
    Rolls(int);
    Rolls(const Rolls&);
    void operator=(const Rolls&);
    int First();
    int Second();
};
