/// @file coin.cpp
/// @brief Class Coin definition
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#include "../include/coin.hpp"

/// @brief Parameterized Constructor. Receives the coin value and builds the object
/// @param value Coin Value
Coin::Coin(float value)
{
	if (value < 0)
		throw NegativeValue();
	value_ = value;
}

/// @brief Returns coin value
float Coin::getValue(void) const { return value_; }

/// Operators Overloads
bool Coin::operator<(const Coin& other) const { return value_ < other.getValue(); }
bool Coin::operator<=(const Coin& other) const { return value_ <= other.getValue(); }
bool Coin::operator==(const Coin& other) const { return value_ == other.getValue(); }
Coin Coin::operator+(const Coin& other) const { return Coin(getValue() + other.getValue()); }

/// @brief Output operator Overload
std::ostream& operator<<(std::ostream& os, const Coin& coin) {
	float value = coin.getValue();
	std::string type = EURO;

	if ((value > 0) && (value < 1)) {
		value *= 100;
		type = CENT;
	}

	return os << value << type;
}
