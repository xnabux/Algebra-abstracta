#include <iostream>
#include <string>

using namespace std;

class Polybios
{
public:
    Polybios();
    string cifrar(string);
    string descifrar(string);
    string abc = "abcdefghijklmnopqrstuvxyz";

private:
    string indice = "ABCDE";
};

