/// @file cambio.cpp
/// @brief Fichero principal del programa.
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

int main(int argc, char** argv) {
	try {
		int opcion = 1;
		double importe, valorMoneda;
		Greedy monstruoVoraz;
		while (opcion != 0) {
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "Algoritmo Voraz (Greedy) para el cambio de monedas"							  << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "[0] Salir"																		  << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "[1] Devolver una cantidad"														  << endl;
			cout << "[2] Mostrar ultima solucion"													  << endl;
			cout << "[3] Insertar una nueva moneda o billete al programa"							  << endl;
			cout << "[4] Ver las monedas disponibles en el programa"								  << endl;
			cout << "-------------------------------------------------------------------------------" << endl;
			cout << "Introduzca una opcion ---> "; cin >> opcion;
			cout << "-------------------------------------------------------------------------------" << endl;
			switch (opcion) {
				case 1:
					cout << "Importe: "; cin >> importe;
					cout << "-------------------------------------------------------------------" << endl;
					monstruoVoraz.devolver_cambio(importe); cout << monstruoVoraz << endl;
					
					break;
				case 2:
					cout << monstruoVoraz << endl;
					break;
				case 3:
					cout << "Introduzca el valor de la moneda (en euros) de la moneda" 						  << endl;
					cout << "-------------------------------------------------------------------------------" << endl;
					cout << "Valor: "; cin >> valorMoneda;
					cout << "-------------------------------------------------------------------------------" << endl;
					monstruoVoraz.insertarMoneda(Moneda(valorMoneda));
					break;
				case 4:
					set<Moneda> monedas = monstruoVoraz.getMonedas();
					cout << "Disponemos de monedas de: ";
					for (set<Moneda>::iterator it = monedas.begin(); it != monedas.end(); it++) {
						cout << (*it);
						if (it != prev(monedas.end()))
							cout << ", ";
					}
					cout << endl;
					break;
			}
		}
	}
	catch (exception& e) {
		cout << "-------------------------------------------------------------------" << endl;
    	cout << e.what() << endl;
    	cout << "-------------------------------------------------------------------" << endl;
	}
	return 0;
}
