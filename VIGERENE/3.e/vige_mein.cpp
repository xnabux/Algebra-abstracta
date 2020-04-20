


#include "vigerne_Enca.h"

using namespace std;

int main() {
	string mensaje("Puedo escribir los versos mas tristes esta noche.Escribir, por ejemplo La noche esta estrellada, y tiritan, azules, los astros, a lo lejos.El viento de la noche gira en el cielo y canta. Puedo escribir los versos mas tristes esta noche. Yo la quise,y a veces ella tambien me quiso.");
	vigerne_2 cover;
	vigerne_2 emisor;
	vigerne_2 receptor;



	string covertir = cover.insertar(mensaje);
	cout << endl << "MENSAJE + AQUI: " << endl;
	cout << covertir << endl;

	string msg = emisor.cifrar(covertir);
	cout << endl << endl << "MENSAJE CIFRADO: " << endl << endl;
	cout << msg << endl << endl;


	string msg_descifrado = receptor.descifrar(msg);
	cout << endl << endl << "MENSAJE DESCIFRADO: " << endl;
	cout << msg_descifrado << endl;
}