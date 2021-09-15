/// @file greedy.hpp
/// @brief Greedy Class. Contains the greedy algorithm responsible for the counting of change
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <set>
#include <cmath>

#include "change.hpp"

/// EU Coins
const Coin ONE_CENT (0.01);
const Coin TWO_CENTS (0.02);
const Coin FIVE_CENTS (0.05);
const Coin TEN_CENTS (0.10);
const Coin TWENTY_CENTS (0.20);
const Coin FIFTY_CENTS (0.50);
const Coin ONE_EURO (1);
const Coin TWO_EUROS (2);
const Coin FIVE_EUROS (5);
const Coin TEN_EUROS (10);
const Coin TWENTY_EUROS (20);

/// Precision constant
const float EPSILON = 1E-4;

/// @class Greedy
class Greedy {
  private:
    Change change_;				//!< Result of the algorithm
    std::set<Coin> coins_;		//!< Set of all type of coins available
    
  public:
    Greedy(const std::set<Coin>& = std::set<Coin> { ONE_CENT, TWO_CENTS, FIVE_CENTS, TEN_CENTS, 
                                                  TWENTY_CENTS, FIFTY_CENTS, ONE_EURO, TWO_EUROS, 
                                                    FIVE_EUROS, TEN_EUROS, TWENTY_EUROS } );
    
    std::set<Coin> getCoins(void) const;
    Change getChange(void) const;
    
    Change returnChange(float);
    void insertCoin(const Coin);
};

/// Output operator Overload
std::ostream& operator<<(std::ostream&, const Greedy&);
