#ifndef GRAPH_H_
#define GRAPH_H_

#include <string>
#include <iostream>
#include <vector>
#include <iterator>
#include <fstream>
#include <stack>
#include <queue>

using namespace std;

class Graph {
  private:
    int nodes;
    int connections;
    vector <int> *adjList;
    string fileName;
    void readFile();
    int edjesList;
    int edjesMat;
    string res;
    void addEdjeAdjList(int u, int v);
    void sortAdjList();
    void ordenaSeleccion(vector<int> &v);
    void swapArray(vector<int> &v, int i, int j);

    string printBFS(bool visit[], int first, int goal, int parent[], int path[]);
    void BFShelper(int first, int current, int goal, bool visited[],int parent[], queue <int> &queue, int path[]);

  public:
    void loadGraphMat(string f, int n, int c);
    void loadGraphList(string f, int n, int c);
    void printAdjList();
    string BFS(int current, int goal);
};

//Constructor
void Graph::loadGraphList(string f, int n, int c){
  fileName = f;
  nodes = n; //Numero de valores
  connections = c; //Numero de conexiones entre valores
  adjList = new vector <int> [nodes]; //Arreglo de vectores
  edjesList = 0;

  readFile(); //Lee los nodos y sus conexiones
}

//Añade conexiones entre el nodo u y el nodo v
void Graph::addEdjeAdjList(int u, int v){
  adjList[u].push_back(v); //Guarda al nodo v en el arreglo del nodo u
  adjList[v].push_back(u); //Guarda al nodo u en el arreglo del nodo v
  edjesList ++; //Aumenta la cuenta de conexiones
}

//Lee las relaciones entre nodos
void Graph::readFile(){
  string first; //u en string
  string second; //v en string
  int u;
  int v;
  string line; //cada línea del archivo de texto
  ifstream file(fileName);
  if (file.is_open()) {
      int i = 0;
      while (getline(file, line)) { //recorre todas las líneas del archivo

        first = line.substr(line.find("(")+1, line.find(",")-1);//encuentra u
        second = line.substr(line.find(" ")+1, line.find(")")-1);//encuentra v

        u = stoi(first); //convierte el primer nodo a int
        v = stoi(second); //convierte el segundo nodo a int
        addEdjeAdjList(u, v); //añade la relación entre nodos
        i++;
      }
      file.close(); //cierra archivo
  }
  sortAdjList(); //ordena los nodos de menor a mayor
}

//Imprime la lista de adyacencia en un archivo de texto
void Graph::printAdjList(){
  string list;
  int number;
  string cadena;
  for(int i = 0; i<nodes; i++){ //Por cada nodo
    list = list + "\nConexiones de la estacion ";
    list = list + to_string(i); //Guarda su identificador
    list = list + " : ";
    for (int j= 0; j < adjList[i].size(); j++){ //Por cada conexion con otro nodo
      int number = adjList[i][j];
      string cadena = to_string(number);
      list = list + cadena; //Guarda su identificador
      list = list + " ";
    }
  }
  ofstream fileTwo ("g2.txt");
  if (fileTwo.is_open()){ //Se abre el archivo
      fileTwo << list << "\n"; //Se imprime la lista completa
  }

  fileTwo.close();//Cierra el archivo
}

//Ordena los nodos
void Graph::sortAdjList(){
  for(int i = 0; i<nodes; i++) //Por cada arreglo
    ordenaSeleccion(adjList[i]); //Ordena su lista
}

//Ordena de menor a mayor
void Graph::ordenaSeleccion(vector<int> &v) {
  for (int i=0; i<v.size()-1; i++){ //Por cada valor
    int min = i;
    for (int j=i+1; j<v.size(); j++){ //Busca un valor que sea menor a él
      if (v[j]<v[min])
        min = j;
    }
    swapArray(v, i, min); //Si hay un nuevo min, intercambia el valor actual de i por min
  }
}

//Intercambia el valor de posición i por el valor de la posición en j
void Graph::swapArray(vector<int> &v, int i, int j) {
	int temp = v[i]; //guarda el lugar i en variable temporal
	v[i] = v[j]; //Sobreescribe j en i
	v[j] = temp; //Recupera i de la variable temporal y lo guarda en j
}

//Encuentra el path que toma menos pasos
string Graph::BFS(int current, int goal){
   int first = current;
  bool *visit = new bool[nodes]; //Arreglo con 1 en los nodos visitados y 0 en los no visitados
  int *parent = new int[nodes]; //Arreglo con el identificador del nodo padre en el índice del nodo hijo
  queue <int> queue; //Queue para recorrer el grafo
  int *path = new int[nodes]; //Historial de los nodos recorridos
  queue.push(first);
  path[0] = current;

  //Se inicializa visit con 0
  for (int i = 0; i < nodes; i++){
    visit[i] = false;
  }

  //Se inicializa parent
  for (int i = 0; i < nodes; i++){
    parent[i] = false;
  }

  //Se inicializa path
  for (int i = 0; i < nodes; i++){
    path[i] = -1;
  }

  //Se manda a llamar a la función que encontrará el camino
  BFShelper(first, current, goal, visit, parent, queue, path);
  return res; //Se imprime el camino
}

//Función recursiva que recorre el grafo
void Graph::BFShelper(int first, int current, int goal, bool visit[], int parent[], queue <int> &queue,int path[]){
  if (current == goal){ //Si ya se encontró el nodo buscado
    if (!queue.empty()) //Si el queue no está vacío
    res = printBFS(visit, first, goal, parent, path); //Imprimir camino más rápido
  }

  else if(queue.empty()) //Si no se encuentra el nodo
    cout << "Una de las estaciones no existe\n"; //Imprimir que el nodo no está en el grafo

  else{
    current = queue.front(); //El nodo actual es el primero del queue
    queue.pop(); //Se elimina primer nodo del queue
    visit[current] = true; //El nodo se marca como visitado
    for (int i = 0; i < adjList[current].size(); i++){ //Se recorre la lista del nodo actual (current)
        if(!visit[adjList[current][i]]){ //Si no se ha visitado el valor de la lista
            queue.push(adjList[current][i]); //Se añade al queue
            if(path[adjList[current][i]] == -1){ //Si el índice del valor de la lista no ha sido modificado en el path
              path[adjList[current][i]] = current; //Se define como current
              parent[adjList[current][i]] = current; //El padre del valor de la lista es current
            }
        }
    }
    BFShelper(first, current, goal, visit, parent, queue, path); //Se repite el proceso hasta terminar la lista de adyacencia o encontrar el nodo
  }
}

//Imprime el camino más corto
string Graph::printBFS(bool visit[], int first, int goal, int parent[], int path[]){

  string print = "Tome las siguientes paradas:";
  vector <int> qu;
  qu.push_back(goal); //Guarda el nodo objetivo en un vector
  while (goal != first){ //Mientras que no se encuentre el nodo inicial
    qu.push_back(parent[goal]); //Se guarda el padre del nodo en el vector
    goal = parent[goal]; //Goal se convierte en su padre hasta encontrar al nodo que no tiene padre
  }

  for (int i = qu.size()-1; i>=0; i--){ //Se recorre el vector con el camino más corto
    print = print + " ";
    print = print + to_string(qu[i]); //Se guarda cada número
  }
  return print; //Se imprime la lista
}

#endif
