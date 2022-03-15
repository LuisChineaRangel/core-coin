/// @file change.hpp
/// @brief Change Class Header
#pragma once
#include <set>
#include <vector>
#include <utility>
#include <algorithm> 

#include "coin.hpp"

/** @name EU Official Coins */
/// @brief All types of coins existing in the European Union
/// @{
const Coin ONE_CENT (0.01);
const Coin TWO_CENTS (0.02);
const Coin FIVE_CENTS (0.05);
const Coin TEN_CENTS (0.10);
const Coin TWENTY_CENTS (0.20);
const Coin FIFTY_CENTS (0.50);
const Coin ONE_EURO (1);
const Coin TWO_EUROS (2);

const std::set<Coin> EU { ONE_CENT, TWO_CENTS, FIVE_CENTS, TEN_CENTS, TWENTY_CENTS, FIFTY_CENTS, ONE_EURO, TWO_EUROS };
/// @}

/// @class Change
/// @brief Represents a solution for money change. It stores the amount of coins for solution and a pair of vectors
/// containing all types of coins needed and their respectives amounts.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Change solution;
/// solution.insertCoin(ONE_CENT);
/// std::cout << solution;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Change {
  private:
    /// Number of all coins
    unsigned amount_;
    /// Set of all types of coins and their respective amount  
    std::pair<std::vector<unsigned>, std::vector<Coin>> change_;

  public:
    /** @name Constructors and Destructor */
    /// @{
    Change(void);
    ~Change();
    /// @}
    
    /** @name Getters */
    /// @{
    unsigned getAmount(void) const;
    std::vector<unsigned> getAmountEachType(void) const;
    std::vector<Coin> getCoins(void) const;
    /// @}

    /** @name Auxiliar Public Functions */
    /// @{
    void clear(void);
    void insertCoin(const Coin&);
    /// @}
};

std::ostream& operator<<(std::ostream&, const Change&);
