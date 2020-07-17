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
#include "funciones.h"

using namespace std;
using namespace NTL;

class rsa{
private:
	zz clave_d = zz(0);
	ZZ clave_e = ZZ(0);
	ZZ N = ZZ(0);
	ZZ p = ZZ(0);
	ZZ q = ZZ(0);
	ZZ clave = ZZ(0);

public:
	string abecedario;
	rsa(int tam);
	rsa(ZZ _N, ZZ key, ZZ _p = ZZ(0), ZZ _q = ZZ(0));
	string Cifrar(string _mensaje);
	string Descifrar(string _mensaje_cifrado);
};



void agregar_ceros(long long tam_N, string& bloque) {
	string ceros(tam_N - bloque.size(), '0');// Calculo tamaño para agregar "ceros"
	ceros += bloque;// Agrego ceros 
	bloque = ceros;// igualo bloque  = 0
}

rsa::rsa(int tam) {
	ZZ p, q;
	vector<ZZ> rango = calcular_rango(ZZ(tam));// 

	
	//p = Generar_Aleatorio(tam, rango);
	//q = Generar_Aleatorio(tam, rango);

	N = p * q; // Generamos "N"
	ZZ phi_N = (p - 1) * (q - 1); // Generamos "fi_de_N"

	do {
		clave_e = RandomBnd(phi_N);// "RandomBnd" Para generara aleatorios de zz de "0" a "phi_N" 
	} while (mcd(clave_e, phi_N) != 1);// Generamos clave "e"

	clave_d = inversa(clave_e, phi_N);// Generamos la clave "d"

	cout << "\nClaves generadas: " << endl;
	cout << "P: " << p << endl;
	cout << "Q: " << q << endl;
	cout << "N: " << N << endl;
	cout << "E: " << clave_e << endl;
	cout << "D: " << clave_d << endl;
}// fin rsa emisor


rsa::rsa(ZZ _N, ZZ key, ZZ _p, ZZ _q)
{
	abecedario = "ABCDEFGHIJKLMNOPQRSTUVWXYZ,.-( )abcdefghijklmnopqrstuvwxyz<>*1234567890";
	clave = key;
	N = _N;
	p = _p;
	q = _q;
}// fin rsa receptor

string rsa::Cifrar(string _mensaje) {
	string mensaje_cifrado; // Lo que retornamos que es el mensaje cifrado
	string pos_alf; // Posicion del alfabeto
	ZZ size_msj = ZZ(_mensaje.size());// Tamaño del alfabeto
	string tam_abc = to_string(abecedario.size()); // Tamaño del alfabeto que se convierte en caracter
	long long num_dig_abc = tam_abc.size();// Para numero de digitos del alfabeto
	
	string tam_N = ZZ_to_string(N);
	long long num_dig_N = tam_N.size(); // Tamaño de la clave "N"
	long long size_bloque = num_dig_N - 1; // Para los bloques el numero de digitos (N-1)


	// Generamos el string con las posiciones de las letras del mensaje, incluyendo la modificacion del tamaño 
	for (long long i = 0; i < size_msj; i++) {
		ZZ pos(abecedario.find(_mensaje[i])); // Posicion de la letra en el "abecedario"
		string _pos = ZZ_to_string(pos); // Llamamos a la funcion para convertir;
		
		if (_pos.size() < num_dig_abc)// Condicion para agregar 
			agregar_ceros(num_dig_abc, _pos);
		pos_alf += _pos;

	} // Fin for

	// Agregamos la posicion de la letra menos usada si necesitaramos mas valores para crear los bloques(Es decir para ceparalos como si fuera un # como en la diapositivas)
	if (modulo(ZZ(pos_alf.size()), ZZ(size_bloque)) > ZZ(0)) {
		int pos = abecedario.find("w"); // Para ceparar los bloques con la letra "w"
		string pos_letra = to_string(pos);// Lo convertimos en caracteres
		int sizepos_ = pos_letra.size(); // Tamaño del caracter que se convirtio
		ZZ modu = modulo(ZZ(pos_alf.size()), ZZ(size_bloque));// Conprobamos
		ZZ diferencia = ZZ(size_bloque) - modu; // Para separara los bloques

		if (diferencia > sizepos_){// Si se cumple
			for (int i = 0; i < diferencia - sizepos_; i++)
				pos_letra += pos_letra[i]; // agregmamos las letras a una variable
		}

		for (int i = 0; i < diferencia; i++) {
			pos_alf += pos_letra[i];// LO que guardamos en una variable  lo agragamos a la posicion del alfabeto
		}
	}// Fin if

	//	Generamos los bloques y los agregamos a un vector de string que los almacenara
	vector<string>bloques;
	for (long long i = 0; i < pos_alf.size(); i += size_bloque){
		string bloque = pos_alf.substr(i, size_bloque);// Una subcadena de "i" hasta size_bloque
		bloques.push_back(bloque);// "push_back"  Agrega un nuevo elemento al final del vector
	}

	//Realizamos el cifrado de cada bloque
	for (long long i = 0; i < bloques.size(); i++)
	{
		ZZ pos_aux = string_to_ZZ(bloques[i]);// Llamamos a la funcion para convertir
		ZZ Q = exp_modular(pos_aux, clave, N); // Llamamos a la funcion para generar la clave "Q"
		string valor = ZZ_to_string(Q); //to_string Q
		if (valor.size() < num_dig_N)// Condicion
			agregar_ceros(num_dig_N, valor);// Agregamos los ceros a valor
		mensaje_cifrado += valor;// Al mesnaje que voy a retornar agramamos los ceros si cumplia con la condicion anterior
	}
	return mensaje_cifrado; // retornamos el mensaje cifrado
}// Fin cifrado

string rsa::Descifrar(string _mensaje_cifrado) {
	string mensaje_descifrado; // La variable que va a contener mi mensaje decifrado
	string letras_descifradas;// Posicion de la letras decifradas
	string tam_N = ZZ_to_string(N);// Llamamos a la funcion para convertir
	long long num_dig_N = tam_N.size(); // Numeros de digitos de "N" (que es la clave)
	long long size_bloque = num_dig_N - 1;// Tamaño de cada bloque
	string tam_abc = to_string(abecedario.size());// El tamaño del "abecedario se convierte a caracteres"
	long long num_dig_abc = tam_abc.size();// Cantidad de digitos de mi tamaño del alfabeto que ya fue convetido a string

	//Creamos los bloques del mensaje descifrado segun el size de N
	vector<string> bloques;
	long long tope = _mensaje_cifrado.size() / num_dig_N;// HAsta donde va mi bloque (su tamño)
	for (long long i = 0; i < tope; i++)
	{
		string bloque = _mensaje_cifrado.substr(0, num_dig_N);// "substr" de 0 a num_dig_N lee
		bloques.push_back(bloque);// LO agregamos al vector "bloques"
		_mensaje_cifrado.erase(0, num_dig_N);// "erase" eleimina un rango de elementos ( [primero, último) 

	}
	

	//return mensaje_descifrado;


}// Fin descifrar




