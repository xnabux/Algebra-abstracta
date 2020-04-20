
#include "vigerene_3_Enca.h"
#include <iostream>

using namespace std;
int main()
{
    string mensaje("MODIFIQUE EL CIFRADO");

    vigenere emisor;
    vigenere receptor;
    vigenere ascii;

    string msg = emisor.cifrar(mensaje);
    cout << endl << endl << "msg CIFRADO: " << endl ;
    cout << msg << endl << endl;


    string msg_descifrado = receptor.descifrar(msg);
    cout << endl << endl << "msg DESCIFRADO: " << endl;
    cout << msg_descifrado << endl;
}