
#include <iostream>
#include <string>
#include <sstream>

#include <fstream>
#include <stdlib.h>

using namespace std;

void EjecicioUno();
//void EjecicioDos();
void EjecicioTres(string);
void EjecicioCuatro();
void EjecicioCinco();
void EjecicioSeis();
void EjecicioSiete();
void EjecicioOcho();
void EjecicioNueve();
void EjecicioDiez();
void EjecicioOnce();
void EjecicioDoce();
void EjercicioTrece();


int main() {
    cout << " ------------  PRACTICA DEL LABORATORIO  ------------\n\n";

    cout << "EJERCIO NUMERO  1\n";
    string cadena1 = "La PalaBRA";
    EjecicioUno();


    cout << "\n\nEJERCIO NUMERO  2\n";
    cout << "La funcion -- capacity -- de un objeto estring es el numro de caracteres que se puede almacenar (su capacidad)\ny la funcion -- size -- es el numero de caracteres almacenados en el objeto string \n\n";

    cout << "EJERCIO NUMERO  3\n";
    EjecicioTres(cadena1);


    cout << "EJERCIO NUMERO  4\n";
    EjecicioCuatro();

    cout << "\nEJERCIO NUMERO  5\n";
    EjecicioCinco();

    cout << "\nEJERCIO NUMERO  6\n";
    EjecicioSeis();


    cout << "\nEJERCIO NUMERO  8\n";
    EjecicioOcho();


    cout << "\nEJERCIO NUMERO  9\n";
    EjecicioNueve();


    cout << "\nEJERCIO NUMERO  10\n";
    EjecicioDiez();


    cout << "\nEJERCIO NUMERO  11\n";
    EjecicioOnce();


    cout << "\nEJERCIO NUMERO  12\n";
    EjecicioDoce();

    cout << "\nEJERCIO NUMERO  13\n";
    EjercicioTrece();


}





//Ejecicio 1
void EjecicioUno()
{
    string cadena = "La paLABRA";
    char cadena2[cadena.length()];

    for (int i = 0; i < cadena.length(); i++)
    {
        cadena2[i] = cadena[i];
        cout << cadena2[i];
    }
}

//Ejecicio 3

void EjecicioTres(string palabra)
{
    string cadena = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cadena2 = "abcdefghijklmnopqrstuvwxyz";

    for (int i = 0; i < palabra.length(); i++)
    {
        for (int j = 0; j < cadena.length(); j++)
        {
            if (palabra[i] == cadena2[j])
            {
                palabra[i] = cadena[j];
            }
            else if (palabra[i] == cadena[j])
            {
                palabra[i] = cadena2[j];
            }
        }
    }

    cout << palabra;
}

//Ejecicio 4

void EjecicioCuatro()
{
    ostringstream cadenaSalida;
    string cadena1;
    string cadena2;
    int valor1;
    int valor2;
    cout << "ingrese primer numero:\n";
    cin >> valor1;
    cout << "ingrese segundo numero:\n";
    cin >> valor2;

    cadenaSalida << cadena1 << valor1;
    cadenaSalida << cadena2 << valor2;
    cout << "primera salida  " << cadenaSalida.str();
    valor1 = valor1 * 2;
    valor2 = valor2 * 2;
    cout << "\nsegunda salida multiplicado por 2  " << cadenaSalida.str();

}



//Ejecicio 5

void EjecicioCinco()
{
    string cadena1(1000, 'a');
    cout << cadena1;
}



//Ejercicio 6
void EjecicioSeis() {

    string cadena1 = "Yo desaprobe el curso de Algebra Abstracta";
    string cadena2, cadena3, cadena4;
    cadena2.append(cadena1, 0, 3);
    cadena3.append(cadena1, 6, cadena1.length());

    cadena4 = cadena2 + cadena3;
    cout << cadena1 << "  CAMBIO A ->   " << cadena4;

}


//Ejercicio 7******
void EjecicioSiete() {
    string a, b;
    int found = -1, cont = 0;
    cout << "INGRESE FRASE: \n";
    getline(cin, a);
    cout << "INGRESE PALABRA: \n";
    cin >> b;

    do {
        found = a.find(b, found + 1);
        if (found != -1) {
            cont++;
        }
    } while (found != -1);
    cout << "\nse encontro la palabra " << b << " " << cont << " veces \n";
}





//Ejercicio 8
void EjecicioOcho() {
    string cadena1;


    cout << "INGRESE LA PALABRA:\n";
    cin >> cadena1;
    string::const_iterator iterador = cadena1.begin();
    //string::const_iterator iterador2 = cadena1.end();
    cout << "ITERACION A TRAVES DEL OBJETO STRING:\n";
    while (iterador != cadena1.end()) {
        cout << *iterador;
        iterador++;
    }
}


//Ejercicio 9
void EjecicioNueve() {
    string a, b;
    cout << "INGRESE LA PRIMERA PALABRA\n";
    cin >> a;
    while (a.length() % 2 != 0) {
        cout << "INGRESE OTRA PALABRA..\n";
        cin >> a;
    }
    cout << "INGRESE LA SEGUNDA PALABRA\n";
    cin >> b;
    a.insert(a.length() / 2, b);
    cout << a;
}

//Ejercicio 10
void EjecicioDiez() {
    string a, b, c;
    cout << "ingrese la frase: \n";
    getline(cin, a);
    cout << "ingrese una palabra: \n";
    cin >> b;
    cout << "ingrese otra palabra: \n";
    cin >> c;
    int pocision = -1;
    do {
        pocision = a.find(b, pocision + 1);
        if (pocision != -1) {
            a.replace(pocision, c.length(), c);
        }

    } while (pocision != -1);
    cout << a;
}


//Ejercicio 11
void EjecicioOnce() {
    string a("boton"), b("computadora");
    string datos("abcdefhijklmnopqrstuvwxyz");
    cout << "palabras: \n" << a << "\n" << b << "\n\n";
    int x, y, i = 0;
    bool z{ false };
    while (z != true) {
        x = datos.find(a.at(i));
        y = datos.find(b.at(i));
        if (x == y) {
            i++;
        }
        else if (x > y) {
            cout << "palabra lexicograficamente mayor: " << a << "\n";
            z = true;
        }
        else {
            cout << "palabra lexicograficamente mayor: " << b << "\n";
            z = true;
        }
    }
}


//Ejercicio 12
void EjecicioDoce() {
    ifstream archivo;
    string texto;
    int op, cont = 0;
    cout << "ingrese un numero del 1 al 10\n";
    cin >> op;
    archivo.open("numeros.txt", ios::in);
    if (archivo.fail()) {
        cout << "\nNO SE PUEDO ABRIR EL ARCHIVO";
        exit(1);
    }
    while (!archivo.eof() && cont < op) {
        getline(archivo, texto);
        cout << texto << "\n";
        cont = cont + 1;
    }
    archivo.close();
}


//Ejercicio 13
void EjercicioTrece() {
    ifstream archivo;
    string texto;
    int sum = 0, a;
    archivo.open("numeros.txt", ios::in);
    if (archivo.fail()) {
        cout << "\nNO SE PUEDO ABRIR EL ARCHIVO";
        exit(1);
    }
    while (!archivo.eof()) {
        getline(archivo, texto);
        a = stoi(texto);
        sum = sum + a;
    }
    cout << "la sumatoria de los numeros en el archivo es: \n" << sum;
}