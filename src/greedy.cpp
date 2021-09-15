/// @file greedy.cpp
/// @brief Greedy Class Definition
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#include "../include/greedy.hpp"

/// @brief Parameterized Constructor. Receives the set with all types of coins availables
/// @param coins Set of coins
Greedy::Greedy(const std::set<Coin>& coins) : coins_(coins) {}

std::set<Coin> Greedy::getCoins() const { return coins_; }
Change Greedy::getChange() const { return change_; }

/// @brief Calculates solution for change to return
/// @param toChange Amount of money to change
Change Greedy::returnChange(float toChange) {
  change_.clean();
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

/// @brief Insertar una nueva coin a nuestro conjunto de coins disponibles.
/// @param coin Nueva coin disponible
void Greedy::insertCoin(const Coin coin) { coins_.insert(coin); }

/// @brief Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Greedy& voraz) {
  os << voraz.getChange();
  return os;
}