#include "cesar.h"

Cesar::Cesar()
{
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    clave = 3;
}


string Cesar::cifra(string mensaje)
{
    int tam = alfabeto.length();
    int ax;
    for (int i = 0; i < mensaje.length(); i++)
    {
        inden = alfabeto.find(mensaje[i]);
        ax = inden + clave;
        if (mensaje[i] == ' ')
        {
            mensaje[i] = alfabeto[inden];
        }
        else
        {
            mensaje[i] = alfabeto[(ax) % tam];
        }
    }
    return mensaje;
}

string Cesar::descifrar(string mensaje)
{
    int tam = alfabeto.length();
    int ax;
    for (int i = 0; i < mensaje.length(); i++)
    {
        inden = alfabeto.find(mensaje[i]);
        ax = inden - clave;
        if (mensaje[i] == ' ')
        {
            mensaje[i] = alfabeto[inden];
        }
        else
        {
            mensaje[i] = alfabeto[(ax) % tam];
        }
    }
    return mensaje;
}