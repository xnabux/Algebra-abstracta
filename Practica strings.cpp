//tuve problemas para presentar le envia un correo el 7 de abril
//
//


#include <iostream>
#include <string>
#include <sstream>
using namespace std;

  void EjecicioUno (string );
  void EjecicioTres(string );
  void EjecicioCuatro();
  void EjecicioCinco();
  void EjecicioSeis();
  void EjecicioOcho();




  int main(){
    cout<<" ------------  PRACTICA DEL LABORATORIO  ------------\n\n";
    //1.
    cout<<"EJERCIO NUMERO  1\n";
    string cadena1="La PalaBRA";
    EjecicioUno(cadena1);


    //2.
    cout<<"\n\nEJERCIO NUMERO  2\n";
    cout<<"La funcion -- capacity -- de un objeto estring es el numro de caracteres que se puede almacenar (su capacidad)\ny la funcion -- size -- es el numero de caracteres almacenados en el objeto string \n\n";

    //3
    cout<<"EJERCIO NUMERO  3\n";
    EjecicioTres(cadena1);

    //4.
    cout<<"EJERCIO NUMERO  4\n";
    EjecicioCuatro();

    //5.
    cout<<"\nEJERCIO NUMERO  5\n";
    EjecicioCinco();

    //6.
    cout<<"\nEJERCIO NUMERO  6\n";
    EjecicioSeis();

    //8.
    cout<<"\nEJERCIO NUMERO  8\n";
    EjecicioOcho();


  }





  //Ejecicio 1
  void EjecicioUno(string cadena)
  {
    char cadena2[cadena.length()];

    for (int i=0;i<cadena.length();i++)
    {
      cadena2[i]=cadena[i];
      cout<<cadena2[i]<<" ";
    }
  }

  //Ejecicio 3

  void EjecicioTres(string palabra)
  {
    string cadena="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cadena2="abcdefghijklmnopqrstuvwxyz";

    for(int i=0;i<palabra.length();i++)
    {
      for(int j=0;j<cadena.length();j++)
      {
        if (palabra[i]==cadena2[j])
        {
          palabra[i]=cadena[j];
        }
        else if (palabra[i]==cadena[j])
        {
          palabra[i]=cadena2[j];
        }
      }
    }

    cout<<palabra;
  }

  //Ejecicio 4

void EjecicioCuatro()
{
  ostringstream cadenaSalida;
  string cadena1;
  string cadena2;
  int valor1;
  int valor2;
  cout<<"ingrese primer numero:\n";
  cin>>valor1;
  cout<<"ingrese segundo numero:\n";
  cin>>valor2;

  cadenaSalida<<cadena1<<valor1;
  cadenaSalida << cadena2<<valor2;
  cout<<"primera salida  "<<cadenaSalida.str();
  valor1=valor1*2;
  valor2=valor2*2;
  cout <<"\nsegunda salida multiplicado por 2  "<<cadenaSalida.str();

}



  //Ejecicio 5

void EjecicioCinco()
{
  string cadena1(1000,'a');
  cout<<cadena1;
}



//Ejercicio 6
 void EjecicioSeis(){

   string cadena1="Yo desaprobe el curso de Algebra Abstracta";
   string cadena2,cadena3,cadena4;
   cadena2.append( cadena1, 0, 3 );
   cadena3.append(cadena1,6,cadena1.length());

   cadena4=cadena2+cadena3;
   cout<<cadena1<<"  CAMBIO A ->   "<<cadena4;

}

//Ejercicio 8
void EjecicioOcho(){
  string cadena1;


  cout<<"INGRESE LA PALABRA:\n";
  cin>>cadena1;
  string::const_iterator iterador = cadena1.begin();
  //string::const_iterator iterador2 = cadena1.end();
  cout<<"ITERACION A TRAVES DEL OBJETO STRING:\n";
  while (iterador != cadena1.end()) {
    cout<<*iterador;
    iterador++;
  }
}



