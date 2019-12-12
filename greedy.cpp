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

set<Moneda> Greedy::getMonedas() const { return monedas_; }
Solucion Greedy::getSolucion() const { return solucion_; }

Solucion Greedy::devolver_cambio(double aDevolver)
{
	cout << aDevolver << endl;
	solucion_.clean();
	double suma = 0;
	while (suma != aDevolver) {
		cout << suma << " ";
		Moneda moneda (0);
		for(set<Moneda>::reverse_iterator it = monedas_.rbegin(); it != monedas_.rend(); it++) {
			cout << (suma + (*it).getValor()) << " ";
			if ((moneda < (*it) && ((suma + (*it).getValor()) <= aDevolver))) {
				moneda = (*it);
				break;
			}
		}
		if (moneda.getValor() == 0)
			throw noSolucion();
			
		solucion_.insertarMoneda(moneda);
		suma += moneda.getValor();
		cout << endl;
	}
	return solucion_;
}
void Greedy::insertarMoneda(const Moneda moneda) { monedas_.insert(moneda); }

ostream& operator<<(ostream& os, const Greedy& voraz)
{
	os << voraz.getSolucion();
	return os;
}
