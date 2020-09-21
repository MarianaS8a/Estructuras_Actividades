#include "registros.h"

int main() {
    vector <string> datos(30);
    Registros <string> registro;
    registro.readText(datos);
    string firstDate;
    string secondDate;
    registro.insertionSort(datos);
    cout << "Escribe la fecha desde la que deseas buscar (día, mes y año). Por ejemplo 01032013\n";
    cin >> firstDate;

    cout << "Escribe la fecha hasta la que deseas buscar (día, mes y año). Por ejemplo 01032015\n";
    cin >> secondDate;

    int indexfirstDate = registro.binSearch(datos, firstDate);
    int indexsecondDate = registro.binSearch(datos, secondDate);

    if ((indexfirstDate == 0) && (indexsecondDate == 0))
        cout << "No se encontraron datos\n";
    else if ((indexfirstDate == datos.size()) && (indexsecondDate == datos.size()))
        cout << "No se encontraron datos\n";
    else if (indexfirstDate > indexsecondDate)
        cout << "El limite inferior debe de ser mayor al superior\n";
    else {
        for (int i = indexfirstDate; i < indexsecondDate; i++)
                cout << datos[i] << "\n";
    }

    registro.writeText(datos);
  }
