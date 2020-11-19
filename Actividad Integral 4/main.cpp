/*
 * main.cpp
 *
 *  Created on: 30/10/2020
 *      Author: clase
 */

#include <iostream>
#include <cstring>
#include "graph.h"

using namespace std;

int main(int argc, char* argv[]) {

    Graph g;
    Graph star;

    string g_ans, g_ans_2;
    string star_ans, star_ans_2;

    g.loadGraphList("g1.txt", 12, 17);//Se carga el grafo

    //Menú
    cout << "\nBienvenido a Metro Express \n\n";
    cout << "Elige la opción del menú deseada: \n";
    cout << "1) Imprimir el mapa en archivo de texto \n";
    cout << "2) Encontrar la ruta más rápida \n\n";
    cout << "Escribe 0 o cualquier letra para salir del programa \n";

    int respuesta;
    cin >> respuesta; 
    while(respuesta != 0){ //Mientras que el usuario escriba un número distinto a 0
      if(respuesta == 1){ //Si usuario escribe 1
        g.printAdjList(); //Imprime mapa en el archivo g2.txt
      cout << "El mapa se ha impreso\n";
    }
      else if(respuesta == 2){ //Si el usuario escribe 2
        int origin;
        int destination;
        cout << "Escribe la estacion de origen: ";
        cin >> origin; //Se solicita la estación de origen
        cout << "Escribe la estacion destino: ";
        cin >> destination; //Se solicita la estación destino
        cout << "\n";
        cout << g.BFS(origin, destination) << "\n"; //Se regresa el camino más cercano
      }
      else //Si el usuario escribe otro número
        cout << "Entrada invalida\n"; //La entrada no es válida
      cin >> respuesta;
      cout << "\n";

    }
}
