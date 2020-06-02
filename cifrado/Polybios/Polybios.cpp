#include "Polybios.h"

Polybios::Polybios() {

}
int modulo(int a, int n)
{
	int r = a - ((a / n) * n);
	if (r < 0)
	{
		r = a - (((a / n) - 1) * n);
	}
	return r;
}

string Polybios::cifrar(string mensaje) {
	string men_cifra;
	int posi;
	int x;
	int y;

	for (int i = 0; i < mensaje.size(); i++) {
		if (mensaje.at(i) == ' ') {
			men_cifra += ' ';
			i++;
		}
		if (abc.find(mensaje.at(i))) {
			posi = posi - 1;
		}
		x = abc.find(mensaje.at(i)) / 5;
		y = abc.find(mensaje.at(i)) % 5;
		men_cifra += indice[x];
		men_cifra += indice[y];
	}
	return men_cifra;
}

string Polybios::descifrar(string men_cifrado) {
	string men_des;
	int pos;
	int x;
	int y;

	for (int i = 0; i < men_cifrado.size(); i += 2) {
		if (men_des.at(i) == ' ') {
			men_des += ' ';
			i++;
		}
		x = indice.find(men_cifrado.at(i));
		y = indice.find(men_cifrado.at(i + 1));

		pos = (5 * x) + y;

		if (pos > 8) {
			pos++;
		}
		men_des += abc[pos];
	}
	return men_des;
}