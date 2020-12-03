#ifndef TRIE_H_
#define TRIE_H_

#include <fstream>
#include <string>
using namespace std;

//Clase que contiene los atributos de cada nodo
class TrieNode{
  private:
    TrieNode *children[26]; //Cada nodo del Trie puede estar conectado con otras 26 letras para formar una palabra
    bool end; //True cuando el caracter es el último de una palabra y false cuando no lo es

  public:
    friend class Trie; //Para que Trie pueda acceder a los atributos de cada nodo
};

//Clase que coordina a los nodos para formar palabras
class Trie{
  public:
    TrieNode *root; //Objeto nodo que está al inicio de la estrucura
    char word[25];
    Trie(); //Constructor, inicializa
    TrieNode *getnode();
    void insert(string word); //Inserta una palabra
    bool empty(TrieNode *node);
    TrieNode *remove(TrieNode *root, string word, int level);//Elimina una palabra
    void removeHelper(string word);
    bool search(string word); //Busca una palabra
    string find(string word); //Regresa si se encontró o no una palabra
    void readFile(); //Lee archivo con una lista
    void writeText(); //Imprime archivo con lista modificada
    void display(TrieNode *root, char str[], int level); //Recorre la estructura para encontrar las palabras e imprimirlas
    string visualization; //Guarda las palabras encontradas por display
    int size;
};

Trie::Trie(){
  root = getnode();//Se le asigna un objeto tipo nodo a la raíz
  size = 0;
}

TrieNode *Trie::getnode(){
  TrieNode *node = new TrieNode; //Se crea un nuevo nodo
  for (int i = 0; i< 26; i++)
    node -> children[i] = 0; //Se define que aún no tiene conexiones con otros nodos
  node -> end = 0; //Se inicializa como nodo no final
  return node; //Se regresa el apuntador al objeto
}

void Trie::insert(string word){
  TrieNode *current = root; //Se guarda la raiz en current

  for(int i = 0; i<word.length(); i++){ //Para cada letra de la palabra insertada
    int index = word[i] - 'a'; //Se le resta 'a' para que el valor de los índices sean de 0 a 25, en lugar de 97 a 122 como en el código ASCII

    if(!current -> children[index]) //Si en el arreglo del nodo actual no hay un objeto en el índice de la letra
      current -> children[index] = getnode(); //Se le asigna un nodo nuevo

    current = current -> children[index]; //El nodo actual ahora es el nodo hijo que estaba situado en el índice actual
  }
  current -> end = true; //Se declara el último nodo recorrido como el fin de la palabra
  size ++;
}

TrieNode *Trie::remove( TrieNode *root, string word, int level){
  if(size == 0) //Si no hay palabras
    return 0; //regresar 0

  if(level == word.length()){ //Si es la última letra de word
    if(root -> end ) //Si es la última letra de una palabra
      root -> end = 0; //Declararla como no última

    if (empty(root)){ //Si el nodo no tiene hijos
      delete root; //Eliminarlo
    }

    return root;
  }

  int index = word[level]-'a';//Se encuentra el valor de la letra

  root -> children[index] = remove(root -> children[index], word, level+1);//Recursividad para viajar a los otros nodos y eliminarlos

  if(empty(root) && root -> end == false){ //Si el nodo no tiene hijos y no es el último
    delete root; //Eliminarlo
  }

  return root;
}

void Trie::removeHelper(string word){ //Simplifica llamada a remove para el main
  remove(root, word, 0); //Manda a llamar a remove
}

bool Trie::empty(TrieNode *node){
  for(int i = 0; i<26; i++){ //Por cada indice del arreglo de un nodo
    if(node -> children[i]) //Verificar si hay algún valor
      return false; //false si hay valores
  }
  return true;//True si no hay valores
}

bool Trie::search(string word){
  TrieNode *current = root;//Se inicializa un apuntador que guarda la dirección de la raíz

  for(int i = 0; i<word.length(); i++){ //Para cada nodo de la palabra buscada
    int index = word[i] - 'a';// Se le resta a para que cada letra tenga un valor de 0 a 25

    if(!current -> children[index])//Si el índice del arreglo del nodo actual no contiene un objeto
      return false; //La letra no está y por lo tanto tampoco la palabra
    current = current -> children[index]; //Se avanza al siguiente nodo

  }
  return(current -> end && current != 0);//Si se llega a una última letra y el nodo actual no está vacío, regresa true
}

string Trie::find(string word){
  if(search(word) == true) //Si la búsqueda fue exitosa
    return "Se ha encontrado la busqueda\n"; //Se encontró la palabra
  else //En el caso contrario
    return "No se encontro la palabra\n"; //No se encontró la palabra
}

void Trie::readFile(){
  string value;
	ifstream file("textIn.txt");
	if (file.is_open()) { //Abre archivo
	  while (file >> value) { //Lee cada palabra
			insert(value); //Inserta cada palabra
	  }
	  file.close(); //Cierra el archivo
	}
}

void Trie::display(TrieNode *root, char word[], int level){
  //Caso base
  if(root -> end == true){ //Si se llega al final de una palabra
    word[level] = '\0'; //Se escribe este caracter para declarar el final de la palabra
    visualization = visualization + word; //Se guarda el valor de la palabra en una variable
    visualization = visualization + "\n"; //Se añade un enter después de cada palabra
  }

  for(int i = 0; i<26; i++){ //Por cada letra del abecedario
    if(root->children[i]){ //Si el nodo actual tiene un valor
      word[level] = i + 'a'; //Se guarda la letra en el índice del número de recursiones
      display(root->children[i], word, level+1); //Se repite la función ahora con el hijo del nodo, se aumenta el número de recursiones en 1
    }
  }
}

void Trie::writeText(){
  ofstream file ("Catalogo1.txt");
  if (file.is_open()){ //Se abre el archivo
    display(root, word, 0); //Se guardan los valores de la estructura en visualization
    file << visualization << "\n"; //Se imprimen los valores
  }
  file.close();//Cierra el archivo
}

#endif
