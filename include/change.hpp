/// @file change.hpp
/// @brief Change Class Header
#pragma once

#include <vector>
#include <utility>
#include <algorithm> 

#include "coin.hpp"

/// @class Change
class Change {
  private:
    unsigned amount_;												//!< Number of all coins
    std::pair<std::vector<unsigned>, std::vector<Coin>> change_;	//!< Set of all types of coins and their respective amount

  public:
    /** @name Constructors and Destructor */
    /// @{
    Change(void);
    
    void clean(void);
    void insertCoin(const Coin&);
    
    unsigned getAmount(void) const;
    std::vector<unsigned> getAmountEachType(void) const;
    std::vector<Coin> getCoins(void) const;
};

std::ostream& operator<<(std::ostream&, const Change&);
