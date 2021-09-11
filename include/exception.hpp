/// @file exception.hpp
/// @brief Customized exceptions for correct performance of the program
/// @author Luis Marcelo Chinea Rangel\n
/// E-mail: alu0101118116@ull.edu.es \n
/// University of La Laguna \n
/// School of Engineering and Technology\n
/// Computer Engineering\n
//////////////////////////////////////////////////////////////////
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <exception>

/// @class Negative Value
/// @brief Exception Object in case a coin has a negativa value
class NegativeValue : public std::exception {
  public:
    virtual const char* what(void) const throw();
};

/// @class NoSolution
/// @brief Exception Object in case there is no change available
class NoSolution : public std::exception {
  public:
    virtual const char* what(void) const throw();
};
