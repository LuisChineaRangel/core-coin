/// @file greedy.hpp
/// @brief Definiciones de la clase Greedy. Contiene el algoritmo
/// voraz para el calculo del cambio optimo de monedas.
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniera y Tecnologaa\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <set>
#include <cmath>

#include "solucion.hpp"

// Monedas y Billetes base de la Uni�n Europea
const Moneda UN_CENT (0.01);
const Moneda DOS_CENT (0.02);
const Moneda CINCO_CENT (0.05);
const Moneda DIEZ_CENT (0.10);
const Moneda VEINTE_CENT (0.20);
const Moneda CINCUENTA_CENT (0.50);
const Moneda UN_EURO (1);
const Moneda DOS_EUROS (2);
const Moneda CINCO_EUROS (5);
const Moneda DIEZ_EUROS (10);
const Moneda VEINTE_EUROS (20);

// Constante de precision
const float EPSILON = 1E-4;

/// @class Greedy
class Greedy {
	private:
		/// Conjunto de las monedas disponibles. 
		std::set<Moneda> monedas_;

		/// Ultima solucion guardada.
		Solucion solucion_;
	public:
		Greedy(const std::set<Moneda>& = std::set<Moneda> { UN_CENT, DOS_CENT, CINCO_CENT, DIEZ_CENT, 
		                                          			VEINTE_CENT, CINCUENTA_CENT, UN_EURO, DOS_EUROS, 
	                                              			CINCO_EUROS, DIEZ_EUROS, VEINTE_EUROS } );
		
		std::set<Moneda> getMonedas() const;
		Solucion getSolucion() const;
		
		Solucion devolver_cambio(float);
		void insertarMoneda(const Moneda);
};

std::ostream& operator<<(std::ostream&, const Greedy&);
