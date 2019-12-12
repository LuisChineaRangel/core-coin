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
		Greedy monstruo_voraz;
		pair<vector<unsigned int>,vector<Moneda>> solucion = monstruo_voraz.devolver_cambio(25);
		for (size_t i = 0; i < solucion.first.size(); i++)
			if (solucion.first[i] == 1)
				cout << solucion.second[i] << " ";
			else
				cout << solucion.first[i] << "x" << solucion.second[i] << " ";
	}
	catch (exception& e) {
		cout << "---------------------------------------------------------" << endl;
    	cout << e.what() << endl;
    	cout << "---------------------------------------------------------" << endl;
	}
	return 0;
}
