/// @file change.cpp
/// @brief Change Class Source Code
#include "../include/change.hpp"

///////////////////////////////////////////////////////
// CLASS MEMBER FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Default Constructor. 
///
/// Initializes total amount to 0
Change::Change(void) : amount_(0) {}

/// @brief Destructor
///
/// Erases all contents and destroys solution
Change::~Change() {
  clear();
}

/// @brief Amount Getter
/// @return Total Amount of coins
unsigned Change::getAmount(void) const { return amount_; }

/// @brief AmountEachType Getter
/// @return Set with the amounts of each money
std::vector<unsigned> Change::getAmountEachType(void) const { return change_.first; }

/// @brief Coins Getter
/// @return Set with all types of coins
std::vector<Coin> Change::getCoins(void) const { return change_.second; }

/// @brief Clean Method. Resets all values
/// @return Void
void Change::clear(void) {
  amount_ = 0;
  change_.first.clear();
  change_.second.clear();
}

/// @brief Inserts a new Coin in the set. If it already exists, the amount of that coin will be increased by one
/// @param coin Coin to Insert
/// @return Void
void Change::insertCoin(const Coin& coin) {
  if (find(change_.second.begin(), change_.second.end(), coin) == change_.second.end()) {
    change_.first.push_back(1);
    change_.second.push_back(coin);
  }
  else {
    for (size_t i = 0; i < change_.second.size(); i++) {
      if (change_.second[i] == coin)
        change_.first[i]++;
    }
  }
  amount_++;
}

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream which is going to write solution
/// @param change Solution to write
/// @return All the information about the solution
std::ostream& operator<<(std::ostream& os, const Change& change) {
  std::vector<unsigned int> amounts = change.getAmountEachType();
  std::vector<Coin> coins = change.getCoins();
  if (!coins.empty()) {
    os << "Change: {";
    for (size_t i = 0; i < coins.size(); i++)  {
      if (amounts[i] == 1)
        os << coins[i];
      else
        os << amounts[i] << "x" << coins[i];
      if (i != coins.size() - 1)
        os << ", ";
    }
    os << "}" << std::endl;
  }
  os << "Total de coins: " << change.getAmount();
  return os;
}
