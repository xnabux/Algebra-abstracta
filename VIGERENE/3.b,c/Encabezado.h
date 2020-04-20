#include <iostream>
#include <string>
using namespace std;


class vigenere {
public:
    vigenere();
    string cifrar(string);
    string descifrar(string);

    string codigo_ASCII(string);
    string codigo_ASCII_Cifrado(string);

    string alfabeto;

 
private:
    string clave;
};