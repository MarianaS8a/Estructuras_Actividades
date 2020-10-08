#Problemática
Una empresa tiene los datos de sus empleados en el formato ("fechaIngreso Nombre ID"). Los datos están ordenados solamente por la inicial del nombre de los empleados y se necesita que todas las letras del nombre de los empleados se tomen en cuenta para ordenarse y tener un acceso fácil y rápido.

#Linked List
La estructura de lista ligada consiste en objetos de una clase unidos por apuntadores. Al primer dato se le llama head y se utiliza para localizar a todos los demás datos porque es necesario recorrer toda la lista desde el inicio para encontrar el que se busca, ya que la referencia de localización de un elemento es el elemento pasado. Las listas ligadas se utilizan cuando se quiere insertar elementos o eliminarlos. En este caso se utiliza porque la inserción de elementos es más rápida que en la de un arreglo y la estructura se ajusta a la cantidad de datos introducidos, ya que usa memoria dinámica.

#Análisis de complejidad

**Insertion Sort**
InsertionSort es el algoritmo de ordenación más rápido de los vistos en clase para los arreglos que están casi ordenados y son pequeños. Como los datos originales del archivo de texto están un poco ordenados, se utilizó este algoritmo. Su complejidad es O(n^2) en el peor casos porque contiene dos ciclos for. Sin embargo, en el mejor de los casos puede llegar a ser nlogn.

**add()**
El algoritmo recorre la lista con un ciclo while para encontrar el último valor y añadir un índice más. Por lo tanto, se realizan n iteraciones y la complejidad es de O(n).

**findFirst() y findSecond()**
FindFirst busca el primer elemento de la lista con la mayúscula introducida, mientras que findSecond busca el último valor de la lista con la mayúscula introducida. El algoritmo se implementó con un ciclo for que recorre la lista hasta encontrar el valor buscado. Por lo que en el peor de los casos se realizarán n iteraciones para encontrar un valor y la complejidad es de O(n).

**upLetter()**
El algoritmo también utiliza un ciclo for para llegar al indice que se introduce y sustituir el valor del mismo. Consecuentemente, se harán n iteraciones en el peor de los casos y la complejidad es O(n).

**get()**
El algoritmo recorre la lista hasta llegar al indice indroducido por el usuario. En el peor de los casos el usuario puede introducir el índice n, por lo que el algoritmo también tiene complejidad O(n).

**clear**
Elimina todos los elementos de la lista y para ello la recorre de inicio a fin. Consecuentemente tiene complejidad O(n).

#Casos de prueba

**Prueba 1: dentro de los límites**

firstLetter = B;
secondLetter = L;
Resultado:
 14092014 Beatriz 32
 11092018 Carmen 37
 07092020 Claudia 28
 12092019 Daniela 43
 02092018 David 7
 15092018 Esteban 12
 01092013 Estefania 84
 27092019 Fernando 91
 06082013 Gerardo 6
 26092018 Geronimo 67
 06092018 Itzia 92
 22092019 Ixchel 51
 23092018 Jorge 13
 16022020 Jose 34
 25092014 Juan 54
 03092017 Kevin 36
 13092014 Lorena 59


**Prueba 2: dentro de los límites**

firstLetter = J;
secondLetter = Z;
Resultado:
23092018 Jorge 13
 16022020 Jose 34
 25092014 Juan 54
 03092017 Kevin 36
 13092014 Lorena 59
 20092020 Maria 10
 10092016 Mariana 46
 09092020 Maximiliano 5
 21092016 Pablo 12
 28092015 Pedro 62
 04092018 Roberto 50
 12092014 Romina 1
 17092016 Sandra 84
 08092019 Sebastian 49
 18092020 Sergio 66
 05092020 Zack 58


**Prueba 3: caracter inválido**

firstLetter = 67;
secondLetter = -;
Resultado:
No se encontraron datos

**Prueba 4: letra inferior mayor a superior**

firstLetter = 05132016;
secondLetter = 01122014;
Resultado:
El limite inferior debe de ser mayor al superior

**Prueba 5: minúsculas**

firstLetter = a;
secondLetter = d;
Resultado:
No se encontro la primera inicial MAYUSCULA

**Prueba 6: minúsculas**

firstLetter = A;
secondLetter = d;
Resultado:
No se encontro la segunda inicial MAYUSCULA
