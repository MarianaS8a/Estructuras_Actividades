#ifndef REGISTROS_H
#define REGISTROS_H

using namespace std;
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <fstream>


template <class T>
class Registros {
public:
    void readText(vector <string>& v);
    void insertionSort(vector <string>& v);
    int binSearch(vector<string>& v, string);
  	int binSearchAux(vector<string>& v, int low, int high, string num);
    void writeText(vector <string>& v);
private:
  void swapArray(vector<string>& v, int i, int j);
  int value(string k);
  void separateDigits(int num);
  int date[8];

};

template <class T>
void Registros<T>::readText(vector <string>& v) {
//lee el archivo de texto

    string line;
    ifstream file("1.txt");
    if (file.is_open()) {
        int i = 0;
        while (getline(file, line)) {
            v[i] = line;
            i++;
        }
        file.close();
    }

}

template <class T>
void Registros<T>::swapArray(vector<string>& v, int i, int j) {
//intercambia posiciones en un vector
    T temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

template <class T>
void Registros<T>::insertionSort(vector <string>& v) {
    for (int i = 0; i < v.size() - 1; i++) {
        int min = i;
        for (int j = i + 1; j < v.size(); j++) {
            if (value(v[j]) < value(v[min]))
                min = j;
        }
        swapArray(v, i, min);
    }
}

template <class T>
int Registros<T>::value(string k) {
//genera un valor comparable para cada fecha
    int num = stoi(k);
    separateDigits(num);
    int val = (date[0] * 10) + date[1] + ((date[2] * 10) + date[3]) * 100 + ((date[4] * 1000) + date[5] * 100 + date[6] * 10 + date[7]) * 1000;
    return val;
}

template <class T>
void Registros<T>::separateDigits(int num) {
//guarda los dígitos de un número en un arreglo
    if (num <= 0)
        int n;
    else {
        for (int i = 7; i >= 0; i--) {
            int digit = num % 10;
            num /= 10;
            date[i] = digit;
        }
    }
}

template <class T>
int Registros<T>::binSearch(vector<string>& v, string num) {
	return binSearchAux(v, 0, v.size()- 1, num);
}

template <class T>
int Registros<T>::binSearchAux(vector<string>& v, int low, int high, string num) {

		if(high >= low){
			int mid = (high+low)/2;
			if (value(v[mid]) == value(num))
				return mid;
			else if (value(v[mid]) < value(num))
				return binSearchAux(v, mid + 1, high, num);
			else
				return binSearchAux(v, low, mid - 1, num);
		}
		return low;
}

template <class T>
void Registros<T>::writeText(vector <string>& v){
//imprime un vector en un archivo de texto
  ofstream fileTwo ("ordenamiento.txt");
  if (fileTwo.is_open()){
    for(int i = 0; i<v.size(); i++)
      fileTwo << v[i] << "\n";
  }
  fileTwo.close();
}

#endif
