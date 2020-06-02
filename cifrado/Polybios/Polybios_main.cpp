#include "Polybios.h"

int main() {
	string mensaje = "hola como estas";

	Polybios llamar;
	string mensaje_cifrado = llamar.cifrar(mensaje);
	cout << "Mensaje: " << mensaje_cifrado << endl;
	string mensaje_descifrado = llamar.descifrar(mensaje_cifrado);
	cout << "Mensaje descifrado: " << mensaje_descifrado << endl;

	return 0;
}