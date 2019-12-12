/// @file greedy.hpp
/// @brief Definiciones de la clase Greedy. Representa un algoritmo
/// voraz (Greedy) para calcular el cambio óptimo de monedas
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
#include <set>
#include <vector>
#include <utility>
#include <algorithm> 

#include "moneda.hpp"

// Monedas y Billetes base de la Unión Europea
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
const Moneda CINCUENTA_EUROS (50);
const Moneda CIEN_EUROS (100);
const Moneda DOSCIENTOS_EUROS (200);
const Moneda QUINIENTOS_EUROS (500);

class Greedy {
	private:
		set<Moneda> monedas_;
		pair<vector<unsigned int>,vector<Moneda>> solucion_;
	public:
		Greedy();
		Greedy(set<Moneda>);
		
		pair<vector<unsigned int>,vector<Moneda>> devolver_cambio(double);
		void insertarMoneda(const Moneda);
};
