#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "exception.h"
#include <stdio.h>

using namespace std;

template <class T> class List;

template <class T>
class Link {
/*La clase Link guarda los valores de cada elemento de la lista ligada
y los conecta mediante apuntadores*/
private:
	//Constructores
	Link(T);
	Link(T, Link<T>*);
	Link(const Link<T>&);

	T	    value; //Valor de cada elemento de la lista ligada
	Link<T> *next; //Siguiente elemento de la lista

	friend class List<T>;
};

//Constructores
template <class T>
Link<T>::Link(T val):value(val), next(0){}

template <class T>
Link<T>::Link(T val, Link* nxt):value(val), next(nxt) {}

template <class T>
Link<T>::Link(const Link<T> &source):value(source.value), next(source.next) {}

template <class T>
class List{
/*La clase List contiene funciones que modifican a los elementos de la clase link*/
public:
  List();
  ~List();
	void clear();//Elimina los elementos de la lista
	bool empty()const; //Devuelve true si la lista está vacía
	void addFirst(T val) throw(OutOfMemory); //Añade un elemento al inicio de la lista
  void add(T val) throw(OutOfMemory);// Añade un elemento al final de la lista
	int findSecond(char val);// Encuentra el último elemento de la lista que inicia con la letra introducida
	int findFirst(char val);// Encuentra el primer elemento de la lista que inicia con la letra introducida
	void update(int index, string val);//Cambia el valor de un elemento de la lista
	string get(int index) const throw (IndexOutOfBounds, NoSuchElement);//Regresa el valor que tiene un elemento
	void readText();//Lee un archivo de texto y guarda cada renglón en una lista ligada
	void insertionSort();//Ordena la lista alfabéticamente
	void writeText();//Escribe la lista ordenada en un archivo de texto
	void removeFirst();
	void remove(T index);

private:
  Link<T> *head; //Primer elemento de la lista
	int size; //Tamaño de la lista
	bool compare(string k, string r);//Regresa true si el primer parámetro es más grande alfabéticamente
	void swap(int i, int j) throw (IndexOutOfBounds);//Intercambia el valor de dos elementos
};

template <class T>
//Constructor
List<T>::List():head(0),size(0){}

template <class T>
//Destructor
List<T>::~List(){
  clear();
}

template <class T>
//Devuelve true si la lista está vacía
bool List<T>::empty() const {
	return (head == 0);
}

template <class T>
void List<T>::clear() {
//Elimina los elementos de la lista
	Link<T> *p, *q;

	p = head; //Apuntador al primer elemento
	while (p != 0) { //Se recorre la lista hasta el final
		q = p->next;//Se avanza al siguiente elemento
		delete p;//Se elimina el elemento
		p = q;
	}
	head = 0;//Se vacía el primer elemento
	size = 0;//El tamaño de la lista regresa a 0
}

template <class T>
void List<T>::addFirst(T val) throw(OutOfMemory){
//Inserta un elemento al inicio de la lista

	Link<T> *newLink;//Se crea un nuevo elemento
	newLink = new Link<T>(val);//Se le asigna un valor al elemento

	if (newLink == 0) //Comprueba que se haya asignado una dirección de memoria al nuevo elemento
		throw OutOfMemory();
	newLink->next = head; //Se le asigna head al siguiente elemento
	head = newLink; //Se define el elemento nuevo como el nuevo head
	size++; //Se aumenta el tamaño de la lista en uno
}

template <class T>
void List<T>::add(T val) throw(OutOfMemory){
//Añade un nuevo elemento al final de la lista

	Link<T> *newLink, *p;
	newLink = new Link<T>(val); //Crea el nuevo elemento y se le asigna un valor

	if (newLink == 0) { //Se asegura que el elemento haya sido creado
    throw OutOfMemory();
  }

  if (empty()) { //Se asegura que la lista no esta vacía
		addFirst(val);
		return;
	}

  p = head; //Se le asigna el primer elemento a una variable temporal
	while (p->next != 0) { //Se recorre la lista hasta llegar al final
		p = p->next;
	}

	newLink->next = 0; //Se le asigna un valor nulo al siguiente elemento del nuevo elemento
	p->next = newLink; //Se conecta el último elemento con el nuevo elemento
	size++; //Se aumenta el tamaño de la lista en uno
}

template <class T>
int List<T>::findSecond(char val){
//Encuentra el último valor de la lista que empieza con la letra val

	Link<T> *p, *q; //Se declaran dos apuntadores temporales
	p = head; //Se le asigna head al primer elemento temporal
	q = p->next; //Se le asigna el segundo elemento de la lista al segundo apuntador temporal

	for (int i = 0; i<size; i++){ //Se recorre toda la lista
		//Se encuentran los nombres
		string person = p->value; //Se extrae el string de la primera persona
		string nextPerson = q->value; //Se extrae el string de la segunda persona
		char letterPer = person[10]; //Se extrae la inicial de la primera persona
		char letterNexPer = nextPerson[10]; //Se extrae la inicial de la segunda persona

		if ((letterPer == val) && (letterNexPer != val))//Valida que la inicial sea igual pero que la siguente persona no tenga esa inicial
			return i;
		else if ((i == size-2) && (letterNexPer == val))//Valida que el elemento final de la lista contenga la letra que se busca
			return i+1;
		else if ((i == size-2) && (letterNexPer != val))//En el caso de no haber encontrado la letra
			return -1;
		p = p->next; //Avanza al siguiente valor
		q = q->next;//Avanza al siguiente valor
	}
	return -1;
}

template <class T>
int List<T>::findFirst(char val){
//Encuentra el primer valor de la lista que empieza con la letra val

	Link<T> *p; //Se declaran dos apuntadores temporales
	p = head; //Se le asigna head al primer elemento temporal

	for (int i = 0; i<size; i++){ //Se recorre toda la lista
		//Se encuentran los nombres
		string person = p->value; //Se extrae el string de la primera persona
		char letterPer = person[10]; //Se extrae la inicial de la primera persona

		if ((letterPer == val))
			return i;

		p = p->next; //Avanza al siguiente valor
	}
	return -1;
}

template <class T>
void List<T>::update(int index, string val){
//Actualiza elementos de la lista
	Link<T> *p;
	p = head;

	for (int i = 0; i<index; i++){//Encuentra el elemento
		p = p->next;
	}
	p->value = val;//Cambia el valor del elemento
}

template <class T>
string List<T>::get(int index) const throw (IndexOutOfBounds, NoSuchElement) {
//Regresa el valor del indice introducido
	int pos;
	Link<T> *p;

	if (index < 0 || index >= size) { //Asegura que el índice esté dentro de los límites
		throw IndexOutOfBounds();
	}

	if (index == 0) {
		if (empty()) { //Se asegura que la lista no esté vacía cuando se pide el índice "0"
			throw NoSuchElement();
		}
		return head->value;
	}

	p = head;
	pos = 0;
	while (pos != index) { //Se encuentra el valor
		p = p->next;
		pos++;
	}
	return p->value; //Se regresa la posición
}

template <class T>
void List<T>::readText() {
//Lee el archivo de texto
    string value;
    ifstream file("values.txt");
    if (file.is_open()) { //Abre archivo
			string acum;
			int i = 0;
      while (file >> value) { //Lee cada palabra
				if(i < 2){ //Cada 2 palabras
					acum = acum + " " + value; //Separa palabras con espacios y las acumula
					i++;
				}
				else{
					acum = acum + " " + value; //Acumula una última palabra
					add(acum); //Añade el conjunto de palabras a un nuevo elemento de la lista
					acum = ""; //Borra la el conjunto de palabras
					i = 0;
				}

      }
      file.close(); //Cierra
    }

}

template <class T>
bool List<T>::compare(string k,string r) {
//Regresa true si el primer parámetro es mayor alfabéticamente

	for ( int i = 0; int(k[i]) != int(r[i]); i++){//Recorre los caracteres de los nombres
		if (k[i] > r[i]){ //El primero es mayor
			return true;
		}
		else if (k[i] < r[i]){ //El primero no es mayor
			return false;
		}
	}

		return compare(k.substr(1),r.substr(1));// Si el caracter es el mismo se utiliza recursividad para recorrer los demás caracteres
}

template <class T>
void List<T>::swap(int i, int j) throw (IndexOutOfBounds) {
//Intercambia posiciones

//Se asegura de que los índices estén dentro de los límites
	if (i < 0 || i >= size) {
		throw IndexOutOfBounds();
	}

	if (j < 0 || j >= size) {
		throw IndexOutOfBounds();
	}

	string temp;
	temp = get(i); //Se guarda el valor del primer índice en variable temporal
	update(i, get(j)); //Se asigna el valor del segundo índice al primer índice
	update(j, temp); //Se asigna el valor de la variable temporal al segundo índice
}

template <class T>
void List<T>::insertionSort() {
    for (int i = 0; i < size - 1; i++) { //Recorre la lista
        int min = i;
        for (int j = i + 1; j < size; j++) { //Recorre la lista a partir del indice+1
            if (compare(get(min).substr(10),get(j).substr(10))) //Encuentra el valor menor
                min = j; //Asigna el valor menor a min
        }
        swap(i, min);//Intercambia el valor menor con el índice
    }
}

template <class T>
void List<T>::writeText(){
//imprime un vector en un archivo de texto
  ofstream fileTwo ("ordenamiento.txt");
  if (fileTwo.is_open()){ //Se abre el archivo
    for(int i = 0; i<size; i++) //Se recorre la lista
      fileTwo << get(i) << "\n"; //Se imprime cada valor de la lista
  }
  fileTwo.close();//Cierra el archivo
}

template <class T>
void List<T>::removeFirst(){
//Elimina el primer valor
	Link<T> *p;
	p = head;
	head = p->next;

	delete p;
	size --;
}

template <class T>
void List<T>::remove(T index){
//Elimina algun valor de la lista
	if (index ==0)//Se asegura que no sea el primer valor
		removeFirst();

	else{
	Link<T> *p, *q, *r;
	p = head;
	for(int i =0; i==index; i++){ //Busca el índice
		p = p->next;
	}
	q = p;
	p = p->next;
	r = p->next;
	q->next = r;

	delete p; //Lo elimina
	size --;
	}
}

#endif
