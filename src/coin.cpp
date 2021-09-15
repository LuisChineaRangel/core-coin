/// @file coin.cpp
/// @brief Coin Class Source Code
#include "../include/coin.hpp"

///////////////////////////////////////////////////////
// CLASS MEMBER FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Parameterized Constructor. 
///
/// Receives the coin value and builds the object. Default value is 0.
/// @param value Coin Value to copy
Coin::Coin(float value) {
  /// Coins cannot have a negative value
  if (value < 0)
    throw NegativeValue();
  value_ = value;
}

/// @brief Destructor. 
///
/// Resets all attributes and destroys object. See also clear() function.
Coin::~Coin() {
  clear();
}

/// @brief Value Getter
/// @return Coin's Value
float Coin::getValue(void) const { return value_; }

/// @brief Value Setter
void Coin::setValue(float value) { value_ = value; }

/// @brief Logical Operator <
/// @param other Second coin to be compared
/// @return true if coin value is smaller than the other coin, false otherwise
bool Coin::operator<(const Coin& other) const { return value_ < other.getValue(); }

/// @brief Logical Operator <=
/// @param other Second coin to be compared
/// @return true if coin value is smaller or equal than the other coin, false otherwise
bool Coin::operator<=(const Coin& other) const { return value_ <= other.getValue(); }

/// @brief Logical Operator ==
/// @param other Second coin to be compared
/// @return true if coin value is equal than the other coin, false otherwise
bool Coin::operator==(const Coin& other) const { return value_ == other.getValue(); }

/// @brief Logical Operator >
/// @param other Second coin to be compared
/// @return true if coin value is greater than the other coin, false otherwise
bool Coin::operator>(const Coin& other) const { return value_ > other.getValue(); }

/// @brief Logical Operator >=
/// @param other Second coin to be compared
/// @return true if coin value is greater or equal than the other coin, false otherwise
bool Coin::operator>=(const Coin& other) const { return value_ >= other.getValue(); }

/// @brief Arithmetic Operator +
/// @param other Coin to add
/// @return The result of adding this coin plus other
Coin Coin::operator+(const Coin& other) const { return Coin(getValue() + other.getValue()); }

/// @brief Arithmetic Operator -
/// @param other Coin to substract
/// @return The result of adding this coin minus other
Coin Coin::operator-(const Coin& other) const { return Coin(getValue() - other.getValue()); }

/// @brief Private Clean Method. Resets all values
/// @return Void
void Coin::clear(void) { value_ = 0; }

///////////////////////////////////////////////////////
// EXTERNAL FUNCTIONS
///////////////////////////////////////////////////////

/// @brief Output operator Overload
/// @param os Outputstream which is going to write coin
/// @param coin Coin to write
/// @return All the information about the coin
std::ostream& operator<<(std::ostream& os, const Coin& coin) {
  float value = coin.getValue();
  std::string type = EURO;

  if ((value > 0) && (value < 1)) {
    value *= 100;
    type = CENT;
  }

  return os << value << type;
}
