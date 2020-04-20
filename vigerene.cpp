#include "Encabezado.h"

vigenere::vigenere() {
    alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
    clave = "Pablo Neruda";
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
/*
string vigenere::codigo_ASCII(string men_ASCII) {
    int pos_men, pos_cla, pos_sum;
    for (int i = 0; i < men_ASCII.length(); i++) {
        pos_men = int(men_ASCII[i]);
        pos_cla = int(clave[i % clave.length()]);
        pos_sum = pos_cla + pos_men;

        men_ASCII[i] = pos_sum % 122;
    }
    return men_ASCII;
}


string vigenere::codigo_ASCII_Cifrado(string men_cifra) {
    int pos_men, pos_cla, pos_sum;
    for (int i = 0; i < men_cifra.length(); i++) {
        pos_men = alfabeto.find(men_cifra[i]);
        pos_cla = alfabeto.find(clave[i % clave.length()]);
    
        if (pos_men < pos_cla) {

            pos_sum = (pos_men - pos_cla) + alfabeto.length();
        }
        else {
            pos_sum = (pos_men - pos_cla) % alfabeto.length();
        }
        men_cifra[i] = alfabeto[pos_sum];
    }
    return men_cifra;

}

*/