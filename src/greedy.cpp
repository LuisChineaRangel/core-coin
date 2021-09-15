/// @file greedy.cpp
/// @brief Greedy Class Source Code
#include "../include/greedy.hpp"

///////////////////////////////////////////////////////
// CLASS MEMBER FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Parameterized Constructor. 
///
/// Initializes the set of coins availables
/// @param coins Types of coins availables. By default, it will be initialized as the EU Coins
Greedy::Greedy(const std::set<Coin>& coins) : coins_(coins) {}

/// @brief Destructor
///
/// Erases all contents and destroys greedy object
Greedy::~Greedy() {
  clear();
}

/// @brief Coins Getter
/// @return Coin types Availables
std::set<Coin> Greedy::getCoins() const { return coins_; }

/// @brief Change Getter
/// @return Last Solution calculated
Change Greedy::getChange() const { return change_; }

/// @brief Calculates solution for change to return
/// @param toChange Amount of money to change
/// @return Solution calculated
Change Greedy::returnChange(float toChange) {
  change_.clear();
  float sum = 0;
  while (sum != toChange) {
    Coin coin(0);
    for(std::set<Coin>::reverse_iterator it = coins_.rbegin(); it != coins_.rend(); ++it) {
      float result = sum + (*it).getValue();
      if ((coin < (*it)) && ((fabs(result - toChange) < EPSILON) || ((toChange - result) > EPSILON))) {
        coin = (*it);
        break;
      }
    }
    if (coin.getValue() == 0)
      throw NoSolution();
      
    change_.insertCoin(coin);
    sum += coin.getValue();
  }
  return change_;
}

/// @brief Inserts a new type of coin in the available set
/// @param coin Coin to insert
/// @return void
void Greedy::insertCoin(const Coin coin) { coins_.insert(coin); }

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream which is going to write the solution calculated by greedy object
/// @param greedy Greedy Calculator
/// @return All the information about last solution
std::ostream& operator<<(std::ostream& os, const Greedy& greedy) {
  os << greedy.getChange();
  return os;
}