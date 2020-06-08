#include "afin.h"


int main()
{
    int a, b;
    string mensaje;
    cout << "Esccribe tu mensaje: ";
    getline(cin, mensaje);
    cout << endl;

    afin emisor;

    string mensaje_cifrado = emisor.cifrar(mensaje);
    cout <<"\nMensaje cifrado: "<< mensaje_cifrado << endl;


    cout << "\Ingrese la clave a: ";
    cin >> a;
    cout << "\Ingrese la clave b: ";
    cin >> b;
    afin receptor(a, b);

    string mensaje_descirfrado = receptor.descifrar(mensaje);
    cout << mensaje_descirfrado << endl;
    return 0;
}