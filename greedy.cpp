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

/// @brief Constructor parametrizado. Recibe un conjunto de monedas para almacenarlas 
/// en el programa, cambiando la configuración por defecto.
/// @param monedas Conjunto de Monedas a guardar.
Greedy::Greedy(const set<Moneda>& monedas) : monedas_(monedas) {}

/// @brief Getter del Conjunto de Monedas.
set<Moneda> Greedy::getMonedas() const { return monedas_; }
/// @brief Getter de la última solución guardada.
Solucion Greedy::getSolucion() const { return solucion_; }

/// @brief Calcular el cambio, con el mínimo nº de monedas, de un importe solicitado.
/// @param aDevolver Importe a cambiar.
Solucion Greedy::devolver_cambio(float aDevolver)
{
	solucion_.clean();
	float suma = 0;
	while (suma != aDevolver) {
		Moneda moneda(0);
		for(set<Moneda>::reverse_iterator it = monedas_.rbegin(); it != monedas_.rend(); ++it) {
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
ostream& operator<<(ostream& os, const Greedy& voraz)
{
	os << voraz.getSolucion();
	return os;
}
