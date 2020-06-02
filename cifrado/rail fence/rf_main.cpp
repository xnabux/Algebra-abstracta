#include "rf.h"

int main() {
	int clave = 3;
	string mensaje = "hola como estas";
	rail_fence llamar(3);
	string mensaje_cifrado = llamar.cifrado(mensaje);
	cout << "Mensaje cifrado: " << mensaje_cifrado<<endl;
	string mensaje_descifrado = llamar.decifrado(mensaje_cifrado);
	cout << "Mensaje mensaje_descifrado: " << mensaje_descifrado<<endl;
	return 0;

}