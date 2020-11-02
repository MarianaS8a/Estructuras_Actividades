#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include <fstream>
#include "heap.h"

using namespace std;

int main(int argc, char* argv[]) {
	Heap<int> heap(40);
	int option;
	heap.readText();
	cout << "Datos leidos \n";

//Menu
	cout << "Escribe el numero de la opcion deseada:\n\n";
	cout << "1) Ver la ubicacion con mas casos\n";
	cout << "2) Insertar un nuevo dato\n";
	cout << "3) Escribir datos en archivo txt\n";
	cout << "0) Salir del programa\n\n";

	while (option != 0){

		cin >> option; //Se escribe la opción deseada

		if (option == 1){ //Si la opción es 1
			cout << "Ubicacion con mas casos:\n" << heap.top() << "\n\n"; //Se imprime la raíz
		}

		else if (option == 2){ //Si la opción es 2
			string newData;
			cout << "Escribe en el siguiente formato: Casos_Lugar\n";
			cin >> newData; //Se añade un nuevo dato al árbol
			cin.ignore(10000, '\n');
			heap.push(newData);
			cout << "Listo! se han registrado los datos\n\n";
		}


		else if (option == 3){ //Si la opción es 3
			heap.writeText(); //Se escriben los datos del arbol en un archivo de texto
			cout << "Listo! se han impreso los datos en el archivo ordenamiento.txt\n\n";
		}

		else if (option != 0) //Si la opción es otra
			cout << "Opcion no valida\n\n";

	}

}
