#include "afin.h"


afin::afin() {
	abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	generar_clave(abc.size(),a,b);//

}

afin::afin(int clave_a, int clave_b) {
	inver_A = inversa_mul(a, abc.size());
	a = clave_a;
	b = clave_b;
}

///////////


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

int afin::euclide_exten(int a, int b) {
	int r1 = a, r2 = b;
	int s1 = 1, s2 = 0;
	int t1 = 0, t2 = 1;
	int s;
	int t;
	while (r2 > 0)
	{
		int q = r1 / r2;
		int r = r1 - (q * r2);
		r1 = r2; r2 = r;

		s = s1 - (q * s2);
		s1 = s2; s2 = s;

		t = t1 - (q * t2);
		t1 = t2; t2 = t;
	};
	s = s1;
	if (s < 0)
		s = mod(s, b);
	return s;
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

///////////


void afin::generar_clave(int size, int& a, int& b)
{
	srand(time(NULL));
	b = mod(rand(), size);
	do {
		a = rand() % size;
	} while (euclide(a, size) != 1);
}


string afin::cifrar(string mensaje) {
	string men_cifra;
	int posicion;
	for (int i = 0; i < mensaje.size(); i++) {
		posicion = abc.find(mensaje[i]);//mensaje.at(i)
		men_cifra += abc.at(mod((a * posicion + b), abc.size()));
	}
	return men_cifra;
}

string afin::descifrar(string mensaje_cifra) {
	string men_des;
	int posicion;
	for (int i = 0; i < mensaje_cifra.size(); i++) {
		posicion = abc.find(mensaje_cifra[i]);//mensaje.at(i)
		men_des += abc.at(mod(inver_A * (posicion - b), abc.size()));
	}
	return men_des;
}





