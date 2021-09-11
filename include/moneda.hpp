/// @file moneda.hpp
/// @brief Definiciones de la clase Moneda. Representa cualquier 
/// tipo de moneda, ya sea met�lica o en papel (billetes)
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniera y Tecnologaa\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <iostream>
#include <string>

#include "exception.hpp"

// Medidas del euro
const std::string CENTIMO = "c";
const std::string EURO = "Euro";

/// @brief Moneda
class Moneda {
	private:
		/// Valor de la Moneda
		float valor_;
	public:
		Moneda(float = 0);
		
		// Operadores
		float getValor() const;
		bool operator<(const Moneda&) const;
		bool operator<=(const Moneda&) const;
		bool operator==(const Moneda&) const;
		Moneda operator+(const Moneda&) const;
};

std::ostream& operator<<(std::ostream&, const Moneda&);
