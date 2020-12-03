#include <iostream>
#include <cstring>
#include <string>
#include "Trie.h"

using namespace std;


int main(int argc, char* argv[]) {
  Trie inventory;

  cout << "\nBienvenido al catalogo de productos \n\n";
  cout << "Elige la opción del menú deseada: \n";
  cout << "1) Leer el archivo con los articulos del catalogo \n";
  cout << "2) Insertar un nuevo producto \n";
  cout << "3) Eliminar un producto \n";
  cout << "4) Averiguar si vendemos un producto \n";
  cout << "5) Imprimir el catalogo en archivo de texto \n";
  cout << "Escribe 0 o cualquier letra para salir del programa \n";

  int respuesta;
  string word;
  cin >> respuesta;
  while(respuesta != 0){ //Mientras que el usuario escriba un número distinto a 0
    if(respuesta == 1){ //Si usuario escribe 1
      inventory.readFile(); //Imprime mapa en el archivo g2.txt
      cout << "El archivo se ha cargado \n";
    }
    else if(respuesta == 2){ //Si el usuario escribe 2
      cout << "Escribe el producto a insertar con caracteres de a-z:\n";
      cin >> word; //Se solicita la estación de origen
      inventory.insert(word);
      cout << "El producto se ha insertado \n";
    }
    else if(respuesta == 3){
      cout << "Escribe el producto que quieres borrar: ";
      cin >> word;
      if(inventory.search(word)){
        inventory.removeHelper(word);
        cout << "El producto se ha eliminado \n";
      }
      else
      cout << "No se encontro el producto \n";
    }
    else if(respuesta == 4){ //Si el usuario escribe 2
      cout << "Escribe el producto que buscas con caracteres de a-z: ";
      cin >> word; //Se solicita la estación de origen
      cout << inventory.find(word);
    }
    else if(respuesta == 5){ //Si el usuario escribe 2
      inventory.writeText();
      cout << "Listo \n";
    }
    else //Si el usuario escribe otro número
      cout << "Entrada invalida \n"; //La entrada no es válida
    cin >> respuesta;
    cout << "\n";

  }

/*
  //CASOS DE PRUEBA
  Trie prueba;
  int i = 0;

  inventory.readFile();
  inventory.insert("lechuga");
  inventory.insert("agua");

	cout << i++ << " " << ((0 == inventory.search("perro")) ? "success\n" : "fail\n");
	cout << i++ << " " << ((0 == inventory.search("gato")) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == inventory.search("lechuga")) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == inventory.search("aguacate")) ? "success\n" : "fail\n");
	cout << i++ << " " << ((1 == inventory.search("melon")) ? "success\n" : "fail\n");

  inventory.removeHelper("agua");
  inventory.removeHelper("lechuga");
  inventory.removeHelper("fresa");

  cout << i++ << " " << ((1 == inventory.search("aguacate")) ? "success\n" : "fail\n");
  cout << i++ << " " << ((0 == inventory.search("lechuga")) ? "success\n" : "fail\n");
  cout << i++ << " " << ((0 == inventory.search("fresa")) ? "success\n" : "fail\n");
  cout << i++ << " " << ((1 == inventory.search("piña")) ? "success\n" : "fail\n");
  cout << i++ << " " << ((1 == inventory.search("mango")) ? "success\n" : "fail\n");
  cout << i++ << " " << ((0 == inventory.search("agua")) ? "success\n" : "fail\n");

  inventory.writeText();
*/
}
