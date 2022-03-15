/// @file exception.cpp
/// @brief Customized Exceptions Source Code
#include "../include/exception.hpp"

/// @brief NegativeValue Exception message
/// @return String with error message reporting negative value
const char* NegativeValue::what(void) const throw() { return "COIN WITH NEGATIVE VALUE!"; }

/// @brief NoSolution Exception message
/// @return String with warning message reporting no change
const char* NoSolution::what(void) const throw() { return "There is no change available.\nIntroduce more coin types."; }