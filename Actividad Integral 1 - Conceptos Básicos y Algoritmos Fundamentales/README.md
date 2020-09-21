#Análisis de complejidad

**Insertion Sort**
InsertionSort es el algoritmo de ordenación más rápido de los vistos en clase para los arreglos que están casi ordenados y son pequeños. Como los datos originales del archivo de texto están un poco ordenados, se utilizó este algoritmo. Su complejidad es O(n^2) en el peor casos porque contiene dos ciclos for. Sin embargo, en el mejor de los casos puede llegar a ser nlogn.

**Busqueda Binaria**
El algorítmo se utiliza para listas ordenadas. Como el algoritmo reduce el área de búsqueda a medida que se ejecuta, su complejidad es de O(logn). No se tiene que recorrer todo el vector para encontrar un elemento.

#Casos de prueba

**Prueba 1: dentro de los límites**

firstDate = 01122014;
secondDate = 05132016;
Resultado:
15092015,Esteban,12
21092015,Pablo,12
04092016,Roberto,50
08092016,Sebastian,49
11092016,Carmen,37
12092016,Daniela,43


**Prueba 2: por debajo de los límites**

firstDate = 04102000;
secondDate = 03042001;
Resultado:
No se encontraron datos


**Prueba 3: por arriba de los límites**

firstDate = 12052026;
secondDate = 07102028;
Resultado:
No se encontraron datos

**Prueba 4: fechas inferior mayor a superior**

firstDate = 05132016;
secondDate = 01122014;
Resultado:
El limite inferior debe de ser mayor al superior
