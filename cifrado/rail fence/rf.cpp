#include "rf.h"

rail_fence::rail_fence(int a) {
	clave = a;
}

string rail_fence::cifrado(string mensaje) {
	string men_cifra;
	int mov = (clave - 1) * 2;
	int x = mov;
	int y = 0;
	for (int i = 0; i < clave; i++) {
		if (i == 0 || i == (clave - 1)) {
			for (int j = i; j < mensaje.size(); j += mov) {
				men_cifra += mensaje.at(j);
			}
		}
		else {
			for (int j = i; j < mensaje.size(); j += y) {
				men_cifra += mensaje.at(j);
				j += y;
				if (j < mensaje.size()) {
					men_cifra += mensaje.at(j);
				}
			}
		}
		x = x - 2;
		y = y + 2;
	}
	return men_cifra;
}

string rail_fence::decifrado(string men_ci) {
	int mov = (clave - 1) * 2;
	string mensaje_descifrado(men_ci.size(), ' ');
	int x = mov;
	int y = 0;
	int z = 0;

	for (int i = 0; i < clave; i++) {
		if (i == 0 || i == (clave - 1)) {
			for (int j = i; j < men_ci.size(); j += mov) {
				if (z < men_ci.size()) {
					mensaje_descifrado.replace(j, 1, men_ci, z, 1);
					z++;
				}
			}
		}
		else {
			for (int j = i; j < men_ci.size(); j += y) {
				mensaje_descifrado.replace(j, 1, men_ci, z, 1);
				z++;
				j += x;
				if (j < men_ci.size()) {
					mensaje_descifrado.replace(j, 1, men_ci, z, 1);
					z++;
				}
			}
		}
		x = x - 2;
		y = y + 2;
	}
	return mensaje_descifrado;
}