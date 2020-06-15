#include "afin.h"


void afin::generar_clave(int& a, int& b) {
	srand(time(NULL));
	b = mod(rand(), abc.size());
	do {
		a = rand() % abc.size();
	} while (euclide(a, abc.size()) != 1);
}

void afin::mostrar_clave() {
	cout << "\nClave a: " << clave_a << endl;
	cout << "Clave b: " << clave_b << endl;
}

int afin::mod(int a, int b) {
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}

int afin::valor_absoluto(int a) {
	if (a < 0) {
		a = a * -1;
	}
	return a;
}

int afin::euclide_exten(int a, int n) {
	int s1 = 1;
	int s2 = 0;
	while (n > 0) {
		int q = a / n;
		int r = a - q * n;
		a = n;
		n = r;
		int s = s1 - q * s2;
		s1 = s2;
		s2 = s;
	}
	return s1;
}

int afin::euclide(int a, int b) {
	if (valor_absoluto(b) > valor_absoluto(a))
		return euclide(b, a);
	if (b == 0) {
		return a;
	}
	if (mod(a, 2) == 0 && mod(b, 2) == 0) {
		return 2 * euclide(a / 2, b / 2);
	}
	if (mod(a, 2) == 0 && mod(b, 2) == 1) {
		return euclide(a / 2, b);
	}
	if (mod(a, 2) == 1 && mod(b, 2) == 0) {
		return euclide(a, b / 2);
	}
	return euclide((valor_absoluto(a) - valor_absoluto(b)) / 2, b);
}

int afin::inversa_mul(int a, int n) {
	if (euclide(a, n) == 1) {
		int x = euclide_exten(a, n);
		if (x < 0) {
			x = x + n;
		}
		return x;
	}
	else {
		cout << "No tiene inversa\n";
	}
}

afin::afin() {
	abc = "abcdefghijklmnopqrstuvwxyz ";
	generar_clave(clave_a,clave_b);
}

afin::afin(int a, int b) {
	abc = "abcdefghijklmnopqrstuvwxyz ";
	clave_a = a;
	clave_b = b;
	inver_A = inversa_mul(a,abc.size());
}

string afin::cifrar(string mensaje) {
	string mensaje_cifrado;
	int pos;
	for (int i = 0; i < mensaje.size(); i++) {
		pos = abc.find(mensaje.at(i));
		int x = mod((clave_a * pos) + clave_b, abc.size());
		mensaje_cifrado += abc.at(x);
	}
	return mensaje_cifrado;
}

string afin::descifrar(string mensaje_cifra) {
	string mensaje_descifrado;
	int pos;
	//inver_A
	for (int i = 0; i < mensaje_cifra.size(); i++) {
		pos = abc.find(mensaje_cifra.at(i));
		int x = mod(inver_A * (pos - clave_b), abc.size());
		mensaje_descifrado += abc.at(x);
	}
	return mensaje_descifrado;
}