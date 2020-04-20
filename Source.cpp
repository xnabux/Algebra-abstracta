//  	Implementar el cifrado de Vigenere
//      donde se pueda seleccionar el alfabeto (numérico, ASCII, HEX), ingresar el texto plano (por archivo o interface) 
//      y genere el cifrado y descifrado


#include "Encabezado.h"
#include <iostream>

using namespace std;
int main()
{
    string mensaje("Puedo escribir los versos mas tristes esta noche.Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos.El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise,y a veces ella tambien me quiso.");

    vigenere emisor;
    vigenere receptor;
    vigenere ascii;
    
    string men = emisor.cifrar(mensaje);
    cout << "MENSAJE CIFRADO: "  << endl;
    cout << men << endl << endl << endl;


    string msg_descifrado = receptor.descifrar(men);
    cout << "MENSAJE DESCIFRADO: "  << endl;
    cout << msg_descifrado << endl;
       /*
    string msg_ascii = ascii.codigo_ASCII(mensaje);
    cout << endl << endl << "msg ASCII: " << endl;
    cout << msg_ascii << endl;

    string msg_ascii_Cifrado = ascii.codigo_ASCII_Cifrado(msg_ascii);
    cout << endl << endl << "msg ASCII descifrado: " << endl;
    cout << msg_ascii_Cifrado << endl;
    */
    return 0;
}
