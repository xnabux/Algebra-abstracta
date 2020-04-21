#include <iostream>
using namespace std;

void division(int dividendo, int divisor, int& residuo, int& cociente);

int main() {
    cout << "CONDICIONES:\n";
    cout << "\"a\" es un entero\n\"n\" es siempre es positivo\n\"q\" es un entero\n\"r\" es un nonemgativo\n";
    cout << "a = (q x n) + r";
    cout << endl << endl;
    int a, q, n, r;

    cout << "Escriba el DIVIDENDO que se representa con la letra a:";
    cin >> a;

    cout << "\nEscriba el DIVISOR que se representa con la letra n:";
    cin >> n;

    division(a, n ,r, q);
    cout << a << "=(" << q << "*" << n << ")+" << r << endl;

}


void division(int dividendo, int divisor, int& residuo, int& cociente) {
    cociente = dividendo / divisor;
    residuo = dividendo % divisor;

    if (residuo < 0) {
        cociente--;
        residuo = dividendo - (cociente * divisor);
    }
}