#include <iostream>
#include <string>
using namespace std;


class Cesar
{
private:
    int clave, inden;
public:
    Cesar();
    string cifra(string msg);
    string descifrar(string cmsg);
    string alfabeto;


};