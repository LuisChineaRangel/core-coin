/// @file cambio.cpp
/// @brief Fichero principal del programa.
/// @author Luis Marcelo Chinea Rangel\n
/// Correo: alu0101118116@ull.edu.es \n
/// Universidad de La Laguna \n
/// Escuela Superior de Ingenieraa y Tecnologia\n
/// Grado en Ingenieria Informatica\n
/// @date 11/12/2019
//////////////////////////////////////////////////////////////////
#ifdef __unix__         
#elif defined(_WIN32) || defined(WIN32) 
#define OS_Windows
#endif

#include <cstdio>
#include <getopt.h>

#include "../include/greedy.hpp"

void help();
void error();

/// @brief Argumentos del programa
const option long_options[] = { {"help", 0, 0, 'h'}, {0, 0, 0, 0} };

/// @brief Utilizando las clases implementadas, el programa despliega un men� interactivo
/// en el cual el usuario podr� elegir varias opciones relacionadas con el problema del
/// cambio de monedas, como calcular un cambio, a�adir monedas y billetes al programa...
/// @param argc N�mero de Argumentos
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
		std::set<Moneda> monedas;
		Greedy monstruoVoraz;
		
		#ifdef OS_Windows
			system("cls");
		#else
			system("clear");
		#endif
		
		// Men� interactivo
		while (opcion != 0) {
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			std::cout << "Algoritmo Voraz (Greedy) para el cambio de monedas"                              << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			std::cout << "[0] Salir"                                                                       << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			std::cout << "[1] Devolver una cantidad"                                                       << std::endl;
			std::cout << "[2] Mostrar ultima solucion"                                                     << std::endl;
			std::cout << "[3] Insertar una nueva moneda o billete al programa"                             << std::endl;
			std::cout << "[4] Ver las monedas disponibles en el programa"                                  << std::endl;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			std::cout << "Introduzca una opcion ---> "; std::cin >> opcion;
			std::cout << "-------------------------------------------------------------------------------" << std::endl;
			switch (opcion) {
				case 0:
					break;
				case 1:
					std::cout << "Importe: "; std::cin >> importe;
					std::cout << "-------------------------------------------------------------------------------" << std::endl;
					try {
						monstruoVoraz.devolver_cambio(importe); std::cout << monstruoVoraz << std::endl;
					}
					catch (NoSolucion& sinSolucion) {
						std::cout << sinSolucion.what() << std::endl;
					}
					break;
				case 2:
					std::cout << monstruoVoraz << std::endl;
					break;
				case 3:
					std::cout << "Introduzca el valor de la moneda (en euros) de la moneda"                        << std::endl;
					std::cout << "-------------------------------------------------------------------------------" << std::endl;
					std::cout << "Valor: "; std::cin >> valorMoneda;
					monstruoVoraz.insertarMoneda(Moneda(valorMoneda));
					break;
				case 4:
					monedas = monstruoVoraz.getMonedas();
					std::cout << "Disponemos de monedas de: ";
					for (std::set<Moneda>::iterator it = monedas.begin(); it != monedas.end(); ++it) {
						std::cout << (*it);
						if (it != prev(monedas.end()))
							std::cout << ", ";
					}
					std::cout << std::endl;
					break;
				default:
					std::cout << "Opcion Desconocida..." << std::endl;
					break;
			}
			if (opcion != 0) {
				std::cout << "-------------------------------------------------------------------------------" << std::endl;
				std::cin.ignore().get();
				#ifdef OS_Windows
					system("cls");
				#else
					system("clear");
				#endif
			}
		}
	}
	catch (std::exception& e) {
		std::cout << "-------------------------------------------------------------------------------" << std::endl;
    	std::cout << e.what() << std::endl;
    	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	}
	return 0;
}

/// @brief Guia para los usuarios
void help() 
{
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	std::cout << "Ejecuci�n del Programa: ./Cambio"                                                << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
	std::cout << "Una vez iniciado el programa, se abrira al usuario un menu"                      << std::endl;
	std::cout << "interactivo con las distintas opciones del algoritmo"                            << std::endl;
	std::cout << "-------------------------------------------------------------------------------" << std::endl;
}

/// @brief Mensaje de error
void error() {
	std::cout << "Modo de empleo: ./Cambio"                      << std::endl;
	std::cout << "Pruebe �./Cambio --help� para m�s informaci�n"	<< std::endl;
}
