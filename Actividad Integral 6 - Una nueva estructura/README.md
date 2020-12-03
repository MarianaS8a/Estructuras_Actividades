#Problemática
Una empresa tiene un catálogo de productos en venta y necesita hacer búsquedas rápidas cuando sus clientes le preguntan si está disponible algún producto.

#Estructura Trie
Trie se usa principalmente para lograr búsquedas de palabras en un tiempo de O(n). Por ejemplo, motores de búsqueda, correctores ortográficos, y para completar texto automáticamente. La estructura cuenta con nodos de una letra y una raíz. Se llama Trie porque recupera información (viene de retrieval en inglés), ya que Trie puede utilizar un nodo para varias palabras. Por ejemplo, guardar las palabras hola y ola requeriría de tan solo 5 nodos; la raíz, 'h', 'o', 'l', y 'a'. Cada uno de los nodos tiene un arreglo de 26 caracteres para guardar en cada índice el objeto o nodo hijo. En el primer índice del arreglo se guarda el hijo en caso de ser una 'a', en el segundo una 'b' y así sucesivamente.

#Análisis de complejidad

#Insert O(n)
El algorítmo inicia en la raíz de la estructura y accede al índice del arreglo children del valor de la letra (letra - 'a'). Si no hay un valor en el índice del arreglo, crea un nuevo objeto que representa la primera letra. Luego, accede al objeto de la primera letra, busca el índice de la segunda letra en el arreglo children de la primera y si está vacío añade un nuevo nodo. El arreglo realiza este procedimiento el número de caracteres que hay en la palabra, por lo que tiene una complejidad O(n). Un ejemplo es el siguiente:

Se quiere insertar la palabra: "abc"

      1. Se accede a la raíz                                                    raíz
      2. Se accede al índice 'a' (a = 0) y se añade un nodo        [a]    []    []    []    []
      2. Se accede al índice 'b' (b = 1) y se añade un nodo      []   [b]         
      3. Se accede al índice 'c' (c = 2) y se añade un nodo         [] [] [c]

#Remove O(n)
El algorítmo utiliza recursividad para llegar al último nodo de la palabra e ir regresando al primero. Si los nodos no son parte de otra palabra, se eliminan. El algorítmo también es O(n) porque recorre una palabra con n letras hasta eliminarla. Ejemplo: eliminar la palabra ab

Tomando en cuenta que también está la palabra "abc"                       raíz
1. Se accede llega con recursividad b                         [a]    []    []    []    []
2. No se elimina b porque es parte de abc                   []   [b]         
3. Tampoco se elimina a porque es parte de abc                 [] [] [c]

#Search O(n)
El algoritmo recorre con un ciclo for de la misma manera que insert por lo que su complejidad también es O(n). Sin embargo, en este caso  se regresa false si no se encuentra un objeto en algúno de los índices que recorre y si logra llegar al nodo final regresa true. Ejemplo:

Buscar: aac

1. Se accede a la raíz                                                    raíz
2. Se encuentra 'a'                                          [a]    []    []    []    []
2. Se el indíce 'a' del segundo arreglo children no está   []   [b]         
3. El algorítmo regresa false                                [] [] [c]

#Display O(n*m)
El algorítmo recorre la estructura empezando por el primer hijo de la raíz, después el primer hijo de ese último nodo y así sucesivamente hasta que terminen los hijos. Cada que finaliza una palabra se guarda en una variable. Después, continua recorriendo los demás hijos hasta finalizar como una búsqueda en profundidad. La complejidad es O(N*M) donde n es la longitud de la palabra más grande y m es la cantidad de caracteres porque el algorímo puede recorrer todos los arreglos de los nodos en el peor de los casos. Ejemplo:

1. Se accede a la raíz                                                    raíz
2. Se encuentra 'a' y se guarda en un arreglo                [a]    []    []    []    []
2. Se encuentra 'b' y se guarda en un arreglo              []   [b]         
3. Se guarda 'c' en un arreglo                                [] [] [c]
4. Se declara que la palabra ha finalizado
