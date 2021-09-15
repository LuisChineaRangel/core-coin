/// @file exception.cpp
/// @brief Customized Exceptions Headers

#pragma once
#include <exception>

/// @class Negative Value
/// @brief Exception Object in case a coin has a negative value
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Coin euro(-5);
/// if (euro.getValue() < 0)
///   throw NegativeValue();
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class NegativeValue : public std::exception {
  public:
    virtual const char* what(void) const throw();
};

/// @class NoSolution
/// @brief Exception Object in case there is no change available
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Coin money(5); Coin change_av(2);
/// if (money - change_av > 0)
///   throw NoSolution();
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class NoSolution : public std::exception {
  public:
    virtual const char* what(void) const throw();
};
