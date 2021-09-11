/// @file exception.h
/// @brief Excepciones para el correcto Funcionamiento del Programa
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniera y Tecnologaa\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <exception>

/// @class ValorNegativo
/// @brief Excepcion en el caso de que se introduzca una moneda de valor negativo.
class ValorNegativo : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "VALOR DE MONEDA NEGATIVO!";
    }
};

/// @class NoSolucion
/// @brief Excepcion en el caso de que no se halle una solucion.
class NoSolucion : public std::exception {
  public:
    virtual const char* what() const throw() {
      return "No disponemos del cambio para su importe.\nIntroduzca mas tipos de monedas al programa.";
    }
};
