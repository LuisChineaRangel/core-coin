/// @file solucion.cpp
/// @brief Clase Solucion. Representa una solución al cambio de monedas
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
#include "solucion.hpp"

Solucion::Solucion() : cantidad_(0) {}

void Solucion::clean()
{
	cantidad_ = 0;
	conjunto_.first.clear();
	conjunto_.second.clear();
}

unsigned int Solucion::getCantidad() const { return cantidad_; }
vector<unsigned int> Solucion::getCantidadMonedas() const { return conjunto_.first; }
vector<Moneda> Solucion::getMonedas() const { return conjunto_.second; }

void Solucion::insertarMoneda(const Moneda& moneda)
{
	if (find(conjunto_.second.begin(), conjunto_.second.end(), moneda) == conjunto_.second.end()) {
		conjunto_.first.push_back(1);
		conjunto_.second.push_back(moneda);
	}
	else {
		for (size_t i = 0; i < conjunto_.second.size(); i++) {
			if (conjunto_.second[i] == moneda)
				conjunto_.first[i]++;
		}
	}
	cantidad_++;
}

ostream& operator<<(ostream& os, const Solucion& solucion)
{
	vector<unsigned int> cantidades = solucion.getCantidadMonedas();
	vector<Moneda> monedas = solucion.getMonedas();
	if (!monedas.empty()) {
		os << "{";
		for (size_t i = 0; i < monedas.size(); i++)  {
			if (cantidades[i] == 1)
				os << monedas[i];
			else
				os << cantidades[i] << "x" << monedas[i];
			if (i != monedas.size() - 1)
				os << ", ";
		}
		os << "}" << endl;
	}
	os << "Total de monedas: " << solucion.getCantidad();
	return os;
}
