#include <iostream>
#include <string>
using namespace std;


class cesar {
public:
    cesar(string);
    void cifrar();
    void descifrar();
private:
    int a;
    int clave = 3;
    string copia;
    string mensaje;
    string datos = "abcdefghijklmnopqrstuvwxyz";
};