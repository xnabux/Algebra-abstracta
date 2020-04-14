#include "Encabezado.h"
#include <iostream>

using namespace std;
int main()
{
    string mensaje;
    cout << "escribe un mensaje  ";
    getline(cin, mensaje);

    cesar palabra(mensaje);

    palabra.cifrar();
    palabra.descifrar();

    return 0;
}
