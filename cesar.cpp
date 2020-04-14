#include "Encabezado.h"

cesar::cesar(string _mensaje) {
    mensaje = _mensaje;

}

void cesar::cifrar() {
    copia = mensaje;

    cout << "\nPalabra Cifrada: ";

    for (int i = 0; i < copia.length(); i++) {
        a = datos.find(copia[i]);
        if (a == -1)
            cout << " ";

        else {
            if (a <= 23) {
                copia[i] = datos.at(a + 3);
                cout << copia[i];
            }
            else if (a > 23) {
                copia[i] = datos.at((a - datos.length()) + clave);
                cout << copia[i];

            }

        }
    }
   // mensaje.erase(0);
    cout << "\n";
}

void cesar::descifrar() {

    cout << "Palabra Descifrada: ";
    for (int i = 0; i < copia.length(); i++) {


        a = datos.find(copia[i]);
        if (a == -1)
            cout << " ";

        else {
            if (a >= 3) {
                copia[i] = datos.at(a - clave);
                cout << copia[i];
            }
            else if (a < 3 && a >= 0) {
                copia[i] = datos.at(a - clave + datos.length());
                cout << copia[i];

            }

        }
    }
    //copia.erase(0);
    cout << "\n";
}