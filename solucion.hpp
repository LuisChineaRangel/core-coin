/// @file solucion.hpp
/// @brief Definiciones de la clase Solucion. Representa una solución
/// al cambio de monedas
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
#include <vector>
#include <utility>
#include <algorithm> 

#include "moneda.hpp"

class Solucion {
	private:
		pair<vector<unsigned int>,vector<Moneda>> conjunto_;
		unsigned int cantidad_;
	public:
		Solucion();
		
		void clean();
		
		unsigned int getCantidad() const;
		vector<unsigned int> getCantidadMonedas() const;
		vector<Moneda> getMonedas() const;
		
		void insertarMoneda(const Moneda&);
};
ostream& operator<<(ostream&, const Solucion&);
