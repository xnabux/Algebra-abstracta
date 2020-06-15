#include "rsa.h"


int main() {

	string mensaje;
	getline(cin, mensaje);
	rsa llamar;
	llamar.cifrar(mensaje);

	return 0;
}
