#include "afin.h"

int main() {
	string mensaje;
	cout << "Escribe tu mensaje: ";
	getline(cin, mensaje);

	afin emisor;//
	string mensaje_cifrado = emisor.cifrar(mensaje);
	cout << "\nMensaje: " << mensaje_cifrado;
	emisor.mostrar_clave();

	cout << endl << endl;
	
	string mensaje1;
	cout << "Escribe tu mensaje: ";
	getline(cin, mensaje1);

	int a;
	int b;
	cout << "\nIngrese la clave a: ";
	cin >> a;
	cout << "\nIngrese la clave b: ";
	cin >> b;

	afin receptor(a, b);//
	string mensaje_descifrado = receptor.descifrar(mensaje1);
	cout << "\nMensaje descifrado: " << mensaje_descifrado;
}


