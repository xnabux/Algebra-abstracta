#include <stdlib.h>
#include <time.h>
#include <vector>
#include <iostream>
#include <math.h>
#include <NTL/ZZ.h>
#include <sstream>
#include <string>
#include <Windows.h>
#include "psapi.h"


// OPERACIONES NECESARIAS

ZZ modulo(ZZ a, ZZ n)	// FUNCION MODULO
{
	if (n <= 0)
		return ZZ(0);
	if (a < n && a >= 0)
		return a;
	ZZ q(a / n);
	if (a < 0)
		q -= 1;
	return  a - (q * n);
};

ZZ mcd(ZZ a, ZZ b) // FUNCION EUCLIDE (MCD)
{
	ZZ r(modulo(a, b));
	while (r != 0)
	{
		a = b;
		b = r;
		r = modulo(a, b);
	}
	return b;
}

ZZ exp_modular(ZZ base, ZZ exp, ZZ n) // FUNCION EXPONECIACION MODULAR
{
	ZZ x(1);
	base = modulo(base, n);
	while (exp > 0)
	{
		if (modulo(exp, ZZ(2)) == ZZ(1))
			x = modulo(x * base, n);
		exp >>= 1;
		base = modulo((base * base), n);
	}
	return x;
}

vector<ZZ> euclides_ext(ZZ a, ZZ b) // FUNCION EUCLIDES EXTENDIDO
{
	vector<ZZ> valores(3);
	ZZ r1(a), r2(b);
	ZZ x1(1), x2(0);
	ZZ y1(0), y2(1);
	ZZ x;
	ZZ y;
	while (r2 > 0)
	{
		ZZ q = r1 / r2;
		ZZ r = r1 - (q * r2);
		r1 = r2; r2 = r;

		x = x1 - (q * x2);
		x1 = x2; x2 = x;

		y = y1 - (q * y2);
		y1 = y2; y2 = y;
	};

	if (x1 < 0)
		x1 = modulo(x1, b);
	valores[0] = x1; //x
	valores[1] = y1; //y
	valores[2] = r1; //mcd
	return valores;
}

ZZ inversa(ZZ a, ZZ n) // FUNCION INVERSA
{
	if (mcd(n, a) == 1)
	{
		vector<ZZ> results(3);
		results = euclides_ext(a, n);
		ZZ x = results[0];
		return x;
	}
	return ZZ(0);
}

// CONVERSIONES
string ZZ_to_string(ZZ valor) // De ZZ a cadena
{
	stringstream palabra;
	palabra << valor;
	return palabra.str();
}
ZZ string_to_ZZ(string valor)	// Cadena a ZZ
{
	return ZZ(INIT_VAL, valor.c_str());
}
// FIN CONVERSIONES




/*
// FUNCIONES PARA CALCULAR EL RC4

vector<ZZ> calcular_rango(ZZ bits) // CALCULAMOS EL RANGO DE LOS BITS
{
	vector<ZZ> valores(2);
	ZZ inicio = ZZ(1);
	ZZ fin;
	for (int i = 0; i < bits - 1; i++)
		inicio <<= 1;

	fin = inicio << 1;

	valores[0] = inicio;
	valores[1] = fin - 1;
	return valores;
}

vector<ZZ> RC4()
{
	vector<ZZ> seed = Generar_semilla();
	vector<ZZ> S;

	//agregamos a S los numeros de 0 a 256
	for (ZZ i(0); i < 256; i++)
		S.push_back(i);

	ZZ f(0);

	//Inicializacion
	for (long long i = 0, j = 0; i < 256; i++, j++)
	{
		f = modulo((f + S[i] + seed[j]), ZZ(256));
		long long aux = ZZ_to_longlong(f);
		swap_values(S[i], S[aux]);
		if (j + 1 == seed.size())
			j = -1;
	}

	f = 0;
	ZZ i(0);
	ZZ t;
	vector<ZZ>K;

	//Generacion de secuencia cifrante
	for (long long j = 0; j < 8; j++) //64 bits 
	{
		i = modulo(i + 1, ZZ(256));
		long long aux_i = ZZ_to_longlong(i);

		f = modulo(f + S[aux_i], ZZ(256));
		long long aux_f = ZZ_to_longlong(f);

		swap(S[aux_i], S[aux_f]);

		t = modulo(S[aux_i] + S[aux_f], ZZ(256));
		vector<ZZ>valor_en_bits = dec_bin(S[ZZ_to_longlong(t)], 8); //Convertimos el valor de S[t] a 8 bits

		for (long long i = 0; i < valor_en_bits.size(); i++)//Agregamos esos bits al vector final
			K.push_back(valor_en_bits[i]);
	}

	return K;
}
vector<ZZ> DES(int desplazamiento)
{
	vector<ZZ> K = RC4();
	vector<int> PC1, PC2;
	PC1 = { 57,49,41,33,25,17,9,1,58,50,42,34,26,18,10,2,59,51,43,35,27,19,11,3,60,52,44,36,63,55,47,39,31,23,15,7,62,54,46,38,30,22,14,6,61,53,45,37,29,21,13,5,28,20,12,4 };
	PC2 = { 14,17,11,24,1,5,3,28,15,6,21,10,23,19,12,4,26,8,16,7,27,20,13,2,41,52,31,37,47,55,30,40,51,45,33,48,44,49,39,56,34,53,46,42,50,36,29,32 };

	//Permutacion con tabla PC1
	vector<ZZ> K_1;
	for (int i = 0; i < PC1.size(); i++)
		K_1.push_back(K[PC1[i] - 1]);

	//Separacion en bloques de 28 elementos
	vector<ZZ> C0, D0;
	for (int i = 0; i < K_1.size() / 2; i++)
	{
		C0.push_back(K_1[i]);
		D0.push_back(K_1[i + K_1.size() / 2]);
	}

	//Corrimientos
	for (int i = 0; i < desplazamiento; i++)
	{
		corr_izq(C0);    corr_der(D0);
	}

	//Unimos C0 Y D0
	vector<ZZ> C0D0;
	C0D0 = C0;
	for (int i = 0; i < D0.size(); i++)
		C0D0.push_back(D0[i]);

	//Permutacion con tabla PC2
	vector<ZZ> K_2;
	for (int i = 0; i < PC2.size(); i++)
		K_2.push_back(C0D0[PC2[i] - 1]);

	return K_2;
}


*/