/// @file moneda.cpp
/// @brief Clase Moneda. Representa cualquier 
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
#include "moneda.hpp"

Moneda::Moneda(double valor)
{
	if (valor < 0)
		throw valorNegativo();
	valor_ = valor;
}

double Moneda::getValor() const { return valor_; }
bool Moneda::operator<(const Moneda& moneda) const { return valor_ < moneda.getValor(); }
bool Moneda::operator==(const Moneda& moneda) const { return valor_ == moneda.getValor(); }
Moneda Moneda::operator+(const Moneda& moneda) const { return Moneda(getValor() + moneda.getValor()); }

ostream& operator<<(ostream& os, const Moneda& moneda)
{
	double valor = moneda.getValor();
	string medida = EURO;
	if ((valor > 0) && (valor < 1)) {
		valor *= 100;
		medida = CENTIMO;
	}
	os << valor << medida;
	return os;
}
