/// @file greedy.cpp
/// @brief Clase Greedy. Representa un algoritmo
/// voraz (Greedy) para calcular el cambio �ptimo de monedas
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingeniera y Tecnologaa\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#include "../include/greedy.hpp"

/// @brief Constructor parametrizado. Recibe un conjunto de monedas para almacenarlas 
/// en el programa, cambiando la configuraci�n por defecto.
/// @param monedas Conjunto de Monedas a guardar.
Greedy::Greedy(const std::set<Moneda>& monedas) : monedas_(monedas) {}

/// @brief Getter del Conjunto de Monedas.
std::set<Moneda> Greedy::getMonedas() const { return monedas_; }
/// @brief Getter de la �ltima soluci�n guardada.
Solucion Greedy::getSolucion() const { return solucion_; }

/// @brief Calcular el cambio, con el m�nimo n� de monedas, de un importe solicitado.
/// @param aDevolver Importe a cambiar.
Solucion Greedy::devolver_cambio(float aDevolver) {
	solucion_.clean();
	float suma = 0;
	while (suma != aDevolver) {
		Moneda moneda(0);
		for(std::set<Moneda>::reverse_iterator it = monedas_.rbegin(); it != monedas_.rend(); ++it) {
			float resultado = suma + (*it).getValor();
			if ((moneda < (*it)) && ((fabs(resultado - aDevolver) < EPSILON) || ((aDevolver - resultado) > EPSILON))) {
				moneda = (*it);
				break;
			}
		}
		if (moneda.getValor() == 0)
			throw NoSolucion();
			
		solucion_.insertarMoneda(moneda);
		suma += moneda.getValor();
	}
	return solucion_;
}

/// @brief Insertar una nueva moneda a nuestro conjunto de monedas disponibles.
/// @param moneda Nueva moneda disponible
void Greedy::insertarMoneda(const Moneda moneda) { monedas_.insert(moneda); }

/// @brief Sobrecarga del operador de salida
std::ostream& operator<<(std::ostream& os, const Greedy& voraz) {
	os << voraz.getSolucion();
	return os;
}
