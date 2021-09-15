/// @file coin.hpp
/// @brief Coin Class Header
#pragma once
#include <iostream>
#include <string>

#include "exception.hpp"

/** @name Coin Types */
/// @{
const std::string CENT = "c";
const std::string EURO = "Euro";
/// @}

/// @class Coin
/// @brief Represents a coin with a specified float value. It can be used to represent different coin systems acrros 
/// the world like euros, dollars or pounds.
/// ### Example
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~.cpp
/// Coin* euro = new Coin(1);
/// Coin bill = *euro * 25;
/// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
class Coin {
  private:
    /// Coin's economic value
    float value_;

  public:
    /** @name Constructors and Destructor */
    /// @{
    Coin(float = 0);
    ~Coin();
    /// @}
    
    /** @name Getters and Setters */
    /// @{
    float getValue(void) const;
    void setValue(float);
    /// @}

    /** @name Logical Operators Overloading */
    /// @{
    bool operator<(const Coin&) const;
    bool operator<=(const Coin&) const;
    bool operator>(const Coin&) const;
    bool operator>=(const Coin&) const;
    bool operator==(const Coin&) const;
    /// @}

    /** @name Arithmetic Operators Overloading */
    /// @{
    Coin operator+(const Coin&) const;
    Coin operator-(const Coin&) const;
    /// @}

  private:
    /** @name Auxiliar Functions */
    /// @{
    void clear(void);
    /// @}
};

std::ostream& operator<<(std::ostream&, const Coin&);
