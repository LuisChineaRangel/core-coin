/// @file coin.hpp
/// @brief Coin Class. Represents a coin with a specified value
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>

#include "exception.hpp"

/// Coin Types
const std::string CENT = "c";
const std::string EURO = "Euro";

/// @class Coin
/// @brief Coin with a value with logical and arithmetic operators
class Coin {
	private:
		float value_;	//!< Coin Value

	public:
		Coin(float = 0);
		
		/// Operators Overload
		float getValue(void) const;
		bool operator<(const Coin&) const;
		bool operator<=(const Coin&) const;
		bool operator==(const Coin&) const;
		Coin operator+(const Coin&) const;
};

/// Output operator Overload
std::ostream& operator<<(std::ostream&, const Coin&);
