#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <random>
#include <vector>

using namespace std;

class rsa
{
public:
	rsa();
	string cifrar(string);
	string descifrar(string);

	int mod(int, int);
	int valor_absoluto(int);
	int euclide_exten(int, int);
	int euclide(int, int);
	int inversa_mul(int, int);

	int exponencial(int, int, int);

	int n;
	int e;
	string abc = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
private:

	int d;
	int fi_de_N;


};
