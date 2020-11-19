**Problemática**
En el metro es muy común que a las persona se les dificulte encontrar la ruta más rápida de un punto a otro, principalmente de una ciudad desconocida. Es por ello que este programa carga el mapa de un metro que se encuentra en un archivo de texto y encuentra la ruta más rápida de una estación a otra.

**Grafo**
Esta estructura de datos puede guardar puntos y conexiones. Es común aplicarlos para representar redes. Como un sistema de metro es una red, se empleó esta estructura para representarlo y procesar los datos.

**Análisis asintótico**

#loadGraphList
Este algoritmo lee un archivo de texto y llama a la función addEdjeAdjList para añadir la cantidad de conexiones que hay en el archivo de texto. La complejidad de añadir una relación es de O(1) porque solo se marca como true a dos celdas de la matriz que guarda las relaciones entre nodos. Sin embargo, la función loadGraphMat realiza este proceso E veces (la cantidad de edjes). Por lo tanto, la complejidad es O(E).

#BFS O(V+E)
Este algoritmo recorre adjList desde cierto número para encontrar a otro. La diferencia con DFS es que el algorítmo recorre todos los hijos del nodo actual y luego ya continua con los hijos de los hijos. La complejidad es O(V+E) porque el algoritmo puede llegar a recorrer todos los edjes y vertices.

#¿Por qué BFS y no DFS?
BFS visita nivel por nivel, por lo que es más óptimo para encontrar el camino más corto cuando el nodo que se busca está cercano a la raíz y esto facilita la eficiencia al hallar el path.

**Casos de prueba**

#Escribir 1 en el menú
  Se imprime el mapa en archivo de texto

#Escribir 2 en el menú y buscar los paths:
  -2 a 7
  Respuesta: Tome las siguientes paradas: 2 3 6 7
  -2 a 10
  Respuesta: Tome las siguientes paradas: 2 1 0 11 10
  -9 a 5
  Respuesta: Tome las siguientes paradas: 9 8 5
  -10 a 22
  Respuesta: Entrada invalida

#Escribir una letra en el menú
  Termina el programa

#Escribir un número que no es 1, 2 o 0
  Se imprime "Entrada inválida"
