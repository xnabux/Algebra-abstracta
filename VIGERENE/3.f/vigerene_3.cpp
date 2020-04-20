#include "vigerene_3_Enca.h"

vigenere::vigenere() {
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "Segun";
}


string vigenere::mod_clave(string mensaje) {
    int cadena = mensaje.length() - clave.length();
    for (int i = 0; i < cadena; i++) {
        clave += mensaje[i];
    }
    return mensaje;
}

string vigenere::cifrar(string mensaje) {
    int pos_men, pos_cla, pos_sum;

    for (int i = 0; i < mensaje.length(); i++) {
        pos_men = alfabeto.find(mensaje[i]);
        pos_cla = alfabeto.find(clave[i % clave.length()]);

        pos_sum = (pos_men + pos_cla) % alfabeto.length();

        mensaje[i] = alfabeto[pos_sum];

    }

    return mensaje;
}



string vigenere::descifrar(string mensaje_cifrado) {
    int pos_men, pos_cla, pos_sum;

    for (int i = 0; i < mensaje_cifrado.length(); i++) {
        pos_men = alfabeto.find(mensaje_cifrado[i]);
        pos_cla = alfabeto.find(clave[i % clave.length()]);

        if (pos_men < pos_cla) {

            pos_sum = (pos_men - pos_cla) + alfabeto.length();
        }
        else {
            pos_sum = (pos_men - pos_cla) % alfabeto.length();

        }

        mensaje_cifrado[i] = alfabeto[pos_sum];
    }
    return mensaje_cifrado;
}