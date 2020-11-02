#ifndef HEAP_H_
#define HEAP_H_


#include <string>
#include <sstream>
#include "exception.h"
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

template <class T>
class Heap {
private:
	string *data;
	unsigned int tam;
	unsigned int count;

	unsigned int parent(unsigned int) const;
	unsigned int left(unsigned int) const;
	unsigned int right(unsigned int) const;

public:
	Heap(unsigned int) throw (OutOfMemory);
	~Heap();
	bool empty() const;
	bool full() const;
	void push(string val) throw (Overflow);
  string top() throw (NoSuchElement);
	void clear();
	void readText();
	int toInt(string value);
	void writeText();
};

//Constructor
template <class T>
Heap<T>::Heap(unsigned int sze) throw (OutOfMemory) {
	tam = sze;
	data = new string[tam];
	if (data == 0) {
		throw OutOfMemory();
	}
	count = 0;
}

//Destructor
template <class T>
Heap<T>::~Heap() {
	delete [] data;
	data = 0;
	tam = 0;
	count = 0;
}

//Regresa true si el arreglo data está vacío
template <class T>
bool Heap<T>::empty() const {
	if (count == 0)
		return 1;
	else
		return 0;
}

//Regresa true si el arreglo data está lleno
template <class T>
bool Heap<T>::full() const {
	if (count == tam)
		return 1;
	else
		return 0;
}

//Calcula el índice del padre de la posición introducida
template <class T>
unsigned int Heap<T>::parent(unsigned int pos) const {
	return (pos -1)/2;
}

//Calcula el índice del nodo izquierdo de la posición introducida
template <class T>
unsigned int Heap<T>::left(unsigned int pos) const {
	return (2*pos+1);
}

//Calcula el índice del nodo derecho de la posición introducida
template <class T>
unsigned int Heap<T>::right(unsigned int pos) const {
	return (2*pos+2);
}

//Inserta un nuevo valor al arreglo data
template <class T>
void Heap<T>::push(string val) throw (Overflow) {
	if (full()) //Verifica que el arreglo no esté lleno
		throw Overflow();

	unsigned int index = count; //Se toma el número de datos en el árbol

		//mientras que el conteo de árboles sea mayor a 0 y el valor introducido sea mayor a su padre
		while (index > 0 && toInt(val) > toInt(data[parent(index)])){
			data[index] = data[parent(index)]; //El índice actual se convierte en el del padre
			index = parent(index); //El indice anterior del padre ahora es el del índice actual

		}

	data [index] = val; //Se incerta el valor del indice actual
	count++; //Se aumenta la cantidad de valores en uno
}

//Regresa el valor de la raíz
template <class T>
string Heap<T>::top() throw (NoSuchElement){
  if(empty()) //Se asegura que el arreglo no esté vacío
		throw NoSuchElement();

  return data[0];
}

//Se reinicia el conteo de datos
template <class T>
void Heap<T>::clear() {
	count = 0;
}

//Lee el archivo de texto
template <class T>
void Heap<T>::readText() {
	string value;
	ifstream file("values.txt");

	if (file.is_open()) { //Abre archivo
		string acum;
		int i = 0;
		string temp = "";
	  while (file >> value) { //Lee cada palabra
			if(i < 1){ //Guarda la primera palabra
				acum = value;
				i++;
			}
			else{
				acum = acum + " " + value; //Acumula la segunda palabra
				push(acum); //Añade el conjunto de palabras a un nuevo elemento de la lista
				acum = ""; //Borra la el conjunto de palabras
				i = 0;
			}
	  }
	  file.close(); //Cierra
	}
}

//Imprime el arreglo en un archivo de texto
template <class T>
void Heap<T>::writeText(){
  ofstream fileTwo ("ordenamiento.txt");
  if (fileTwo.is_open()){ //Se abre el archivo
    for(int i = 0; i<tam; i++) //Se recorre la lista
      fileTwo << data[i] << "\n"; //Se imprime cada valor de la lista
  }

  fileTwo.close();//Cierra el archivo
}

//Regresa los enteros de un string
template <class T>
int Heap<T>::toInt(string value){
	int newInt = stoi(value);
	return newInt;
}


#endif /* HASH_H_ */
