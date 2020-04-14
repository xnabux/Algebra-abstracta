//tuve problemas para presentar le envia un correo el 7 de abril
//
//




#include <iostream>
#include <string>

using namespace std;

void funcion18_19(string);
void funcion18_21(string);
void funcion18_22(string);



int main (){
  //  18.11 Escriba un programa que introduzca por separado un primer nombre y un apellido, 
  //  y que concatene los dos en un nuevo objeto string.
  
  cout<<"EJERCICIO 18.11\n";
  string cadena1;
  string cadena2;
  string cadena3;
  cout<<"Cual es su primer nombre.\n";
  getline(cin,cadena1);

  cout<<"Cual es su apellido\n";
  getline(cin,cadena2);

  cadena3=cadena1+cadena2;
  cout<<"Su nombre es: "<<cadena3;
  

  //18.19 Escriba un programa que inserte los caracteres "******" en la mitad exacta de un objeto string. 
  cout<<"EJERCICIO 18.19\n";
  string cadena4("ESTERNOCLEIDOMASTOIDEO");
  funcion18_19(cadena4);

  //18.21  Escriba un programa que introduzca una línea de texto, reemplace todos los signos de puntuación con espacios y 
  //utilice la función strtok de la biblioteca de cadenas estilo C para dividir el objeto string en palabras individuales (tokens).
  cout<<"EJERCICIO 18.21\n";
  string cadena5("Para el curso de Algebra Abstracta se debe tener como  conocimiento previo el uso de la  libreria String");
  funcion18_21(cadena5);



  //18.22 Escriba un programa que introduzca una línea de texto y la imprima al revés. Use iteradores en su solución. 
  cout<<"EJERCICIO 18.22\n";
  string cadena6("colecciona todos los tatuajes");
  funcion18_22(cadena6);
}



//EJERCICIO 18.19
void funcion18_19(string cadena1)
{
  cout<<"La palabra sin modificacion    ->  "<<cadena1;
  string cadena2("****");
  cadena1.insert(11,cadena2,0,string::npos);
  cout<<"\nLa palabra con modificacion    ->  "<<cadena1;
}


//EJECICIO 18.21
void funcion18_21(string cadena1)
{
  int posicion = cadena1.find(" ");
  cout<<"\ntexto original\n"<<cadena1;
  while ( posicion != string::npos )
  {
    cadena1.replace( posicion, 1, "." );
    posicion = cadena1.find( " ", posicion + 1 );
  }
  cout <<"\nTexto modificado\n"<<cadena1;
}


//EJECICIO 18.22
  
  
void funcion18_22(string cadena1)
{
   string::const_iterator  iterador = cadena1.end();
   cout << "\nForma normal\n " << cadena1;
   cout<<"\n forma modificada\n";
   while ( iterador != cadena1.begin() -1) 
   {
      cout << *iterador;
      iterador--;
   }
}
