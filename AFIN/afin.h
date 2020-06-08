#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <random>

using namespace std;
class afin
{
public:
	afin();
	afin(int, int);
	string cifrar(string);
	string descifrar(string);
	string abc;

	int mod(int, int);
	int valor_absoluto(int);
	int euclide_exten(int, int);
	int euclide(int, int);
	int inversa_mul(int, int);
	void generar_clave(int,int&,int&);


private:

	int a, b;
	int inver_A;
};

