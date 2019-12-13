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
#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

#include <cstdio>
#include <getopt.h>

#include "greedy.hpp"

void help();
void error();

/// @brief Argumentos del programa
const option long_options[] = { {"help", 0, 0, 'h'}, {0, 0, 0, 0} };

/// @brief Utilizando las clases implementadas, el programa despliega un menú interactivo
/// en el cual el usuario podrá elegir varias opciones relacionadas con el problema del
/// cambio de monedas, como calcular un cambio, añadir monedas y billetes al programa...
/// @param argc Número de Argumentos
/// @param argv Vector de Argumentos
int main(int argc, char** argv)
{
	try {
		// Manejo de argumentos
		int c, option_index;
    	while ((c = getopt_long (argc, argv, "h", long_options, &option_index)) != -1) {
      		switch (c) {
        		case 'h':
        		  help();
        		  return 0;
        		case '?':
        		  break;
        		default:
        		  error();
        		  return 1;
      		}
    	}
    
		int opcion = 1;
		float importe, valorMoneda;
		set<Moneda> monedas;
		Greedy monstruoVoraz;
		
		#ifdef OS_Windows
			system("cls");
		#else
			system("clear");
		#endif
		
		// Menú interactivo
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
				case 0:
					break;
				case 1:
					cout << "Importe: "; cin >> importe;
					cout << "-------------------------------------------------------------------------------" << endl;
					try {
						monstruoVoraz.devolver_cambio(importe); cout << monstruoVoraz << endl;
					}
					catch (NoSolucion& sinSolucion) {
						cout << sinSolucion.what() << endl;
					}
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
					monedas = monstruoVoraz.getMonedas();
					cout << "Disponemos de monedas de: ";
					for (set<Moneda>::iterator it = monedas.begin(); it != monedas.end(); it++) {
						cout << (*it);
						if (it != prev(monedas.end()))
							cout << ", ";
					}
					cout << endl;
					break;
				default:
					cout << "Opcion Desconocida..." << endl;
					break;
			}
			if (opcion != 0) {
				cout << "-------------------------------------------------------------------------------" << endl;
				cin.ignore().get();
				#ifdef OS_Windows
					system("cls");
				#else
					system("clear");
				#endif
			}
		}
	}
	catch (exception& e) {
		cout << "-------------------------------------------------------------------------------" << endl;
    	cout << e.what() << endl;
    	cout << "-------------------------------------------------------------------------------" << endl;
	}
	return 0;
}

/// @brief Guía para los usuarios
void help() 
{
	cout << "-------------------------------------------------------------------------------" << endl;
	cout << "Ejecución del Programa: ./Cambio"        							  << endl;
	cout << "-------------------------------------------------------------------" << endl;
	cout << "Una vez iniciado el programa, se abrira al usuario un menu"		  << endl;
	cout << "interactivo con las distintas opciones del algoritmo"				  << endl;
	cout << "-------------------------------------------------------------------------------" << endl;
}

/// @brief Mensaje de error
void error() {
	cout << "Modo de empleo: ./Cambio"   					<< endl;
	cout << "Pruebe ’./Cambio --help’ para más información"	<< endl;
}
