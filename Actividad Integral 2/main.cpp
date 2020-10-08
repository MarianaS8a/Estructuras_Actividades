
#include <iostream>
#include <sstream>
#include <cstring>
#include <string>
#include "list.h"
#include "exception.h"

using namespace std;

int main(int argc, char* argv[]) {
	List<string> list;
	char firstLetter;//límite superior de la búsqueda
	char secondLetter;//límite inferior de la búsqueda

	list.readText(); //lee el archivo de texto y lo guarda en lista ligada
	list.insertionSort();//ordena la lista ligada

	//Se le pide al usuario las letras con las que empieza y terminan las personas que desea buscar
	cout << "Escribe la inicial MAYUSCULA desde la que deseas buscar\n";
	cin >> firstLetter;

	cout << "Escribe la inicial MAYUSCULA hasta la que deseas buscar\n";
	cin >> secondLetter;

//Excepciones en las que no se encuentre la búsqueda del usuario
	if (firstLetter > secondLetter) //El límite inferior es mayor al superior
		cout << "El limite inferior debe de ser mayor al superior\n";
	else if (list.findFirst(firstLetter) == -1) //La letra que se busca no está en la lista
		cout << "No se encontro la primera inicial MAYUSCULA";
	else if (list.findSecond(secondLetter) == -1) //La letra que se busca no está en la lista
		cout << "No se encontro la segunda inicial MAYUSCULA";
	else {// no hay excepciones y se imprime la lista ordenada
		for (int i = list.findFirst(firstLetter); i <= list.findSecond(secondLetter); i++){
			cout << list.get(i) << "\n";
		}
	}

	list.writeText();// se guarda el ordenamiento en el archivo ordenamiento.txt

}
//g++ -Wno-deprecated exception.h list.h main.cpp
