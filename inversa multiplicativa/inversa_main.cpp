#include <iostream>
#include <string>

using namespace std;

int mod(int a, int b) {
    int r = a - ((a / b) * b);
    if (r < 0)
        r = a - (((a / b) - 1) * b);
    return r;
}

int valor_absoluto(int a) {
    if (a < 0) {
        a = a * -1;
    }
    return a;
}

int euclide_exten(int a, int n) {
    int s1 = 1;
    int s2 = 0;
    while (n > 0) {
        int q = a / n;
        int r = a - q * n;
        a = n;
        n = r;
        int s = s1 - q * s2;
        s1 = s2;
        s2 = s;
    }
    return s1;
}

int euclide(int a, int b) {
    if (valor_absoluto(b) > valor_absoluto(a))
        return euclide(b, a);
    if (b == 0) {
        return a;
    }
    if (mod(a, 2) == 0 && mod(b, 2) == 0) {
        return 2 * euclide(a / 2, b / 2);
    }
    if (mod(a, 2) == 0 && mod(b, 2) == 1) {
        return euclide(a / 2, b);
    }
    if (mod(a, 2) == 1 && mod(b, 2) == 0) {
        return euclide(a, b / 2);
    }
    return euclide((valor_absoluto(a) - valor_absoluto(b)) / 2, b);
}



int inversa_mul(int a, int n) {
    if (euclide(a, n) == 1) {
        int x = euclide_exten(a, n);
        if (x < 0 ) {
            //mod(x, n);
           // x = x + n;
        }
        return x;
    }
    else {
        cout << "No tiene inversa\n";
    }
}

int main() {
    int a = 11;
    int n = 26;
    cout<<inversa_mul(a, n);
    return 0;
}