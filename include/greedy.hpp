/// @file greedy.hpp
/// @brief Greedy Class Header
#pragma once
#include <cmath>

#include "change.hpp"

/// Precision constant
constexpr auto EPSILON = 1E-4;

/// @class Greedy
/// @brief Change Calculator
///
/// Uses a greedy algorithm to calculate the minimun change for a ceratin amount of money
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Greedy machine;
/// machine.getchange(0.50);
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Greedy {
  private:
    /// Result of the algorithm
    Change change_;
    /// Set of all type of coins available
    std::set<Coin> coins_;
    
  public:
    /** @name Constructors and Destructor */
    /// @{
    Greedy(const std::set<Coin>& = EU);
    ~Greedy();
    /// @}
    
    /** @name Getters */
    /// @{
    std::set<Coin> getCoins(void) const;
    Change getChange(void) const;
    /// @}
    
    /** @name Auxiliar Public Functions */
    /// @{
    void clear(void);
    void insertCoin(const Coin);
    Change returnChange(float);
    /// @}
};

std::ostream& operator<<(std::ostream&, const Greedy&);
