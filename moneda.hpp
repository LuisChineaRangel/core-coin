/// @file moneda.hpp
/// @brief Definiciones de la clase Moneda. Representa cualquier 
/// tipo de moneda, ya sea metálica o en papel (billetes)
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
#include <iostream>
#include <string>

#include "exception.hpp"

// Medidas del euro
const string CENTIMO = "c";
const string EURO = "Euro";

/// @brief Moneda
class Moneda {
	private:
		/// Valor de la Moneda
		float valor_;
	public:
		Moneda(float);
		
		float getValor() const;
		bool operator<(const Moneda&) const;
		bool operator<=(const Moneda&) const;
		bool operator==(const Moneda&) const;
		Moneda operator+(const Moneda&) const;
};
ostream& operator<<(ostream&, const Moneda&);
