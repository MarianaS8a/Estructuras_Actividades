#Problemática
Se quiere saber qué ubicación de México tiene más casos de coronavirus para darle mayor prioridad, además de poder añadir nuevos lugares con casos. Los datos están en un archivo de texto con formato: "NúmeroCasos Ubicación".

#Arbol heap
El arbol max-heap guarda el valor con la llave más grande en la raíz. Comunmente se usa como un priority queue. En este caso se utiliza porque se quiere tener a la mano el valor más grande, tomando en cuenta los nuevos valores que añada el usuario durante la ejecución del programa.

#Análisis de complejidad

**push** O(logn)
La función va añadiendo nuevos nodos, primero en la raíz y luego en los subárboles de izquierda a derecha. Sin embargo, la función debe de insertar nuevos nodos forzosamente en lugares en los que su nodo padre es menor a su propio valor. Como se realiza una comparación de valores solo en ciertas secciones del arbol porque éste ya está un poco ordenado, la complejidad es de O(logn)

**top** O(1)
Esta función accede al valor que se encuentra en el primer espacio del arreglo, por lo que no hay ciclos y el algoritmo tiene una complejidad constante en el peor de los casos.

**empty** O(1)
El algoritmo verifica que el valor de la variable count sea 0 para después regresar true o false. Como no se necesita realizar ninguna iteración, la complejidad de la función también es constante.

**parent, left y right** O(1)
Tienen complejidad constante porque no contienen ciclos, solo realizan una operación y regresan un valor.

#Casos de prueba

**Prueba 1: escribir 1 en el menú**

160749 Ciudad_de_Mexico

**Prueba 2: escribir 2 en el menú**

Resultado 1: Escribe en el siguiente formato: Casos_Lugar
Resultado 2: Listo! se han registrado los datos

**Prueba 3: escribir 3 en el menú**

Resultado: se imprimen los valores en archivo txt

**Prueba 4: escribir valor inválido en el menú**

Resultado: Opcion no valida

**Prueba 5: insertar un nuevo valor mayor en el arbol y escribir 1 para ver si se actualizó la raíz**

Resultado: se imprime el valor añadido
