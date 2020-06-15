#include "rsa.h"



int rsa::mod(int a, int b) {
	int r = a - ((a / b) * b);
	if (r < 0)
		r = a - (((a / b) - 1) * b);
	return r;
}

int rsa::valor_absoluto(int a) {
	if (a < 0) {
		a = a * -1;
	}
	return a;
}

int rsa::euclide_exten(int a, int n) {
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

int rsa::euclide(int a, int b) {
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

int rsa::inversa_mul(int a, int n) {
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

int rsa::exponencial(int b, int e, int n) {
	int pow = 1;
	do {
		if (mod(e, 2) != 0) {
			pow = mod(b * pow, n);
		}
		b = mod(b * b, n);
		e /= 2;
	} while (e != 0);
	return pow;
}

rsa::rsa() {
	int p = 17;
	int q = 43;
	n = p * q;
	fi_de_N = (p - 1) * (q - 1);

	srand(time(NULL));
	d = inversa_mul(d, fi_de_N);

	do {
		e = rand() % n;
	} while (euclide(e, fi_de_N) != 1);

	cout << "p " << p << " ,q " << q << endl;
	cout << "n " << n << " ,e " << e << " ,d " << d << endl;
}

string rsa::cifrar(string mensaje) {
	int expo;
	string mensaje_cifrado;
	for (int i = 0; i < mensaje.size(); i++) {
		int pos = abc.find(mensaje[i]);
		mensaje_cifrado += to_string(exponencial(pos, e, n));
		mensaje_cifrado += " ";
		//cout << expo << " , ";
	}
	return mensaje_cifrado;
}

string rsa::descifrar(string mensaje) {
	int expo;
	vector<string> vectorMensaje;
	string mensaje_descrifrado;
	string letra;
	for (int i = 0; i < mensaje.size(); i++) {
		
	}


	return mensaje_descrifrado;
}

