/// @file greedy.cpp
/// @brief Clase Greedy. Representa un algoritmo
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
#include "greedy.hpp"

Greedy::Greedy() 
{
	monedas_ = set<Moneda> {UN_CENT, DOS_CENT, CINCO_CENT, DIEZ_CENT, VEINTE_CENT, CINCUENTA_CENT, UN_EURO, DOS_EUROS};
}
Greedy::Greedy(set<Moneda> monedas) : monedas_(monedas) {}

pair<vector<unsigned int>,vector<Moneda>> Greedy::devolver_cambio(double aDevolver)
{
	solucion_.first.clear(); solucion_.second.clear();
	double suma = 0;
	while (suma != aDevolver) {
		Moneda moneda (0);
		for(set<Moneda>::iterator it = monedas_.begin(); it != monedas_.end(); it++) {
			if ((moneda < (*it) && ((suma + (*it).getValor()) <= aDevolver)))
				moneda = (*it);
		}
		if (moneda.getValor() == 0)
			throw noSolucion();
		if (find (solucion_.second.begin(), solucion_.second.end(), moneda) == solucion_.second.end()) {
			solucion_.first.push_back(1);
			solucion_.second.push_back(moneda);
		}
		else {
			for (size_t i = 0; i < solucion_.second.size(); i++) {
				if (solucion_.second[i] == moneda)
					solucion_.first[i]++;
			}
		}
		suma += moneda.getValor();
	}
	return solucion_;
}
void Greedy::insertarMoneda(const Moneda moneda) { monedas_.insert(moneda); }
