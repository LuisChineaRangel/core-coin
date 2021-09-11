/// @file change.hpp
/// @brief Change Class. Represents the result of change for a specified amount of money
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
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
		Change(void);
		
		void clean(void);
		void insertCoin(const Coin&);
		
		unsigned getAmount(void) const;
		std::vector<unsigned> getAmountEachType(void) const;
		std::vector<Coin> getCoins(void) const;
};

/// Output operator Overload
std::ostream& operator<<(std::ostream&, const Change&);
