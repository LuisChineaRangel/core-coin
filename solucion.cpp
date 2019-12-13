/// @file solucion.cpp
/// @brief Clase Solucion. Representa una soluci�n al cambio de monedas
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingenier�a y Tecnolog�a\n
/// Grado en Ingenier�a Inform�tica\n
/// Asignatura: Computabilidad y Algoritmia (CyA)\n
/// Curso: 2�\n
/// Pr�ctica #12: Algoritmos Voraces (Greedy)
/// @date 11/12/2019
/// @see Enunciado de la pr�ctica:
/// https://campusvirtual.ull.es/1920/mod/assign/view.php?id=21020
//////////////////////////////////////////////////////////////////
#include "solucion.hpp"

/// @brief Constructor por defecto.
Solucion::Solucion() : cantidad_(0) {}

/// @brief Limpia los atributos del objeto.
void Solucion::clean()
{
	cantidad_ = 0;
	conjunto_.first.clear();
	conjunto_.second.clear();
}

/// @brief Getter de la cantidad de monedas de la soluci�n.
unsigned int Solucion::getCantidad() const { return cantidad_; }
/// @brief Getter de las cantidades de cada tipo de monedas.
vector<unsigned int> Solucion::getCantidadMonedas() const { return conjunto_.first; }
/// @brief Getter de los tipos de monedas de la soluci�n.
vector<Moneda> Solucion::getMonedas() const { return conjunto_.second; }

/// @brief Inserta una moneda (nueva o ya existente) en la soluci�n.
/// @param moneda Moneda a insertar
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

/// @brief Sobrecarga del operador de salida.
ostream& operator<<(ostream& os, const Solucion& solucion)
{
	vector<unsigned int> cantidades = solucion.getCantidadMonedas();
	vector<Moneda> monedas = solucion.getMonedas();
	if (!monedas.empty()) {
		os << "Solucion: {";
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
