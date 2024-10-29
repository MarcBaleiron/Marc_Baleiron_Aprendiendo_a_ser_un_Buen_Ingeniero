#include <iostream>
#include "movimientos_caballo.h"
using namespace std;

int main() {
    int resultados[] = {1, 2, 3, 5, 8, 10, 15, 18, 21, 23, 32};
    int numResultados = sizeof (resultados) / sizeof (resultados[0]);

    cout << "Cantidad de movimientos | Posibilidades validas" << endl;
    cout << "------------------------|-----------------------" << endl;

    for (int i = 0; i < numResultados; ++i)
    {
        int movimientos = resultados[i];
        int movs_validos = conteo (movimientos);
        cout << "         " << movimientos << "               |        " << movs_validos << endl;
    }

    return 0;
}