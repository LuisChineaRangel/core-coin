/// @file change.cpp
/// @brief Coin Class definition
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#include "../include/change.hpp"

/// @brief Default Constructor
Change::Change(void) : amount_(0) {}

/// @brief Cleans all atrributes
void Change::clean(void) {
	amount_ = 0;
	change_.first.clear();
	change_.second.clear();
}

unsigned Change::getAmount(void) const { return amount_; }
std::vector<unsigned> Change::getAmountEachType(void) const { return change_.first; }
std::vector<Coin> Change::getCoins(void) const { return change_.second; }

/// @brief Inserts a new Coin in the set. If it already exists, the amount of that coin will be increased by one
/// @param coin Coin to Insert
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

/// @brief Output operator Overload
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
