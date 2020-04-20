#include <iostream>
#include <string>
using namespace std;


class vigenere {
public:
    vigenere();
    string cifrar(string);
    string descifrar(string);
    string mod_clave(string);

    string alfabeto;


private:
    string clave;
};