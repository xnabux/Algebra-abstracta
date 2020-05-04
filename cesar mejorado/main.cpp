#include <iostream>
#include <string>
using namespace std;

#include "cesar.h"

int main() {
    Cesar emisor;
    Cesar receptor;
    string mensaje, cifrado, decifrado;
    getline(cin, mensaje);
    cifrado = emisor.cifra(mensaje);
    decifrado = receptor.descifrar(mensaje);
    cout << cifrado << endl;
    cout << decifrado << endl;

}
