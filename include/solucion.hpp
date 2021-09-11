/// @file solucion.hpp
/// @brief Definiciones de la clase Solucion. Representa una soluci�n
/// al cambio de monedas
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniera y Tecnologaa\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#pragma once
#include <vector>
#include <utility>
#include <algorithm> 

#include "moneda.hpp"

/// @class Solucion
class Solucion {
	private:
		/// Conjunto de la solucion. Cada tipo de moneda va asociado a una cantidad.
		std::pair<std::vector<unsigned int>, std::vector<Moneda>> conjunto_;
		/// Cantidad Total de monedas.
		unsigned int cantidad_;
	public:
		Solucion();
		
		void clean();
		
		unsigned int getCantidad() const;
		std::vector<unsigned int> getCantidadMonedas() const;
		std::vector<Moneda> getMonedas() const;
		
		void insertarMoneda(const Moneda&);
};

std::ostream& operator<<(std::ostream&, const Solucion&);
