#include <iostream>
#include <string>
#include <sstream>


using namespace std;

void funcion18_7();
void funcion18_11();
void funcion18_19(string);
void funcion18_21(string);
void funcion18_22(string);
void funcion_27();



int main() {

    cout << "EJERCICIO 18.7\n";
    funcion18_7();
    cout << endl;
    cout << endl;


    cout << "EJERCICIO 18.11\n";
    funcion18_11();
    cout << endl;
    cout << endl;

    cout << "EJERCICIO 18.19\n";
    string cadena4("ESTERNOCLEIDOMASTOIDEO");
    funcion18_19(cadena4);
    cout << endl;
    cout << endl;

    cout << "EJERCICIO 18.21";
    string cadena5("Para el curso de Algebra Abstracta se debe tener como  conocimiento previo el uso de la  libreria String");
    funcion18_21(cadena5);
    cout << endl;
    cout << endl;

    cout << "EJERCICIO 18.22\n";
    string cadena6("colecciona todos los tatuajes");
    funcion18_22(cadena6);
    cout << endl;
    cout << endl;

    cout << "EJERCICIO 18.27\n";
    funcion_27();

    return 0;
}

//EJECICIO 18.7
void funcion18_7() {
    string palabra, cambio;
    cout << "Ingrese una palabra/frase: ";
    getline(cin, palabra);
    for (int i = 0; i < palabra.length(); i++) {
        char x = palabra[i] + 13;
        cambio += x;
        if (!(isalpha(cambio[i]))) {
            cambio[i] = cambio[i] - 26;
        }
        //cout << cambio[i] << endl;
    }
    cout << "Palabra cifrada: " << cambio << endl;
    cout << "Palabra Original: " << palabra << endl;

}

//EJECICIO 18.11

void funcion18_11() {
    string a, b;
    cout << "Cual es su primer nombre.\n";
    cin >> a;
    cout << "Cual es su apellido\n";
    cin >> b;
    string c(a + b);
    cout << "Su nombre es: " << c;

}

//EJERCICIO 18.19
void funcion18_19(string cadena1)
{
    cout << "La palabra sin modificacion    ->  " << cadena1;
    string cadena2("****");
    cadena1.insert(11, cadena2, 0, string::npos);
    cout << "\nLa palabra con modificacion    ->  " << cadena1;
}


//EJECICIO 18.21
void funcion18_21(string cadena1)
{
    int posicion = cadena1.find(" ");
    cout << "\ntexto original\n" << cadena1;
    while (posicion != string::npos)
    {
        cadena1.replace(posicion, 1, ".");
        posicion = cadena1.find(" ", posicion + 1);
    }
    cout << "\nTexto modificado\n" << cadena1;
}


//EJECICIO 18.22
void funcion18_22(string cadena1)
{
    string::const_iterator  iterador = cadena1.end();
    cout << "\nForma normal\n " << cadena1;
    cout << "\n forma modificada\n";
    while (iterador != cadena1.begin() - 1)
    {
        cout << *iterador;
        iterador--;
    }
}


//EJECICIO 18.27
void funcion_27() {
    string a("hola");
    string b("alo");
}
