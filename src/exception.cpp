/// @file exception.cpp
/// @brief Customized exceptions definition for correct performance of the program
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#include "../include/exception.hpp"

/// @brief NegativeValue message
const char* NegativeValue::what(void) const throw() { return "COIN WITH NEGATIVE VALUE!"; }

/// @brief NoSolution message
const char* NoSolution::what(void) const throw() { return "There is no change available.\nIntroduce more coin types."; }