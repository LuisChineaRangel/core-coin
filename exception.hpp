/// @file exception.h
/// @brief Excepciones para el correcto Funcionamiento del Programa
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniería y Tecnología\n
/// Grado en Ingeniería Informática\n
/// Asignatura: Computabilidad y Algoritmia (CyA)\n
/// Curso: 2º\n
/// Práctica #12: Algoritmos Voraces (Greedy)
/// @date 11/12/2019
/// @see Enunciado de la práctica:
/// https://campusvirtual.ull.es/1920/mod/assign/view.php?id=21020
//////////////////////////////////////////////////////////////////
#pragma once
#include <exception>

using namespace std;

class valorNegativo : public exception {
  public:
    virtual const char* what() const throw() {
      return "¡VALOR DE MONEDA NEGATIVO!";
    }
};

class noSolucion : public exception {
  public:
    virtual const char* what() const throw() {
      return "No disponemos de cambio para su importe.\nPruebe introduciendo mas tipos de monedas al programa.";
    }
};
