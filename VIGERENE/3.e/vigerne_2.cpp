#include "vigerne_Enca.h"

using namespace std;

    string clave;

 vigerne_2::vigerne_2() {
        alfabeto = "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,.";
        clave = "Pablo Neruda";
}



 string vigerne_2::insertar(string mensaje) {
     string cadena = "AQUI";

     for (int i = 10; i < mensaje.length(); i+=14) {
             mensaje.insert(i,cadena); 
     }
     int tam = (((mensaje.length() / 4) + 1) * 4) - mensaje.length();
     for (int i = 0; i < tam; i++) {
         mensaje += "W";
     }
     return mensaje;
}

 string vigerne_2::cifrar(string mensaje) {
     int pos_men, pos_cla, pos_sum;

     for (int i = 0; i < mensaje.length(); i++) {
         pos_men = alfabeto.find(mensaje[i]);
         pos_cla = alfabeto.find(clave[i % clave.length()]);

         pos_sum = (pos_men + pos_cla) % alfabeto.length();

         mensaje[i] = alfabeto[pos_sum];
     }

     return mensaje;
 }




 string vigerne_2::descifrar(string mensaje_cifrado) {
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