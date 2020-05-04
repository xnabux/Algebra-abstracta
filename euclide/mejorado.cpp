#include <iostream>
#include <string>
#include<time.h>
using namespace std;

int conver_posi(int a);
int euclide(int a, int b);
int algoritmo_1(int a, int b);
int algoritmo_2(int a, int b);
int algoritmo_3(int a, int b);
int algoritmo_4(int a, int b);
int algoritmo_5(int a, int b);
int algoritmo_6(int a, int b);


int main() {
    clock_t t, t2;
    t = clock();
    int a = 412;
    int b = 260;
    //euclide(a, b);
    a = algoritmo_6(a, b);
    cout << "MCD= " << a << endl;
    t = clock() - t;
    cout << "\nTIEMPO QUE TARDO EL ALGORITMO 1: " << float(t) / CLOCKS_PER_SEC << " segundos\n";

    return 0;
}


int euclide(int a, int b) {

    if (a >= 0) {
        return a - (b * (a / b));
    }
    else {
        return a - (((a / b) - 1) * b);
    }

}


int conver_posi(int a) {
    if (a < 0) {
        a = a * -1;
    }
    return a;
}

int algoritmo_1(int a, int b) {
    int r = 0;
    while (true) {
        r = euclide(a, b);
        cout << "r= " << r << endl;
        if (r == 0) {
            return b;
        }
        else {
            a = b;
            cout << "a= " << a << endl;
            b = r;
            cout << "b= " << b << endl << endl;
        }
    }//fin while
}

int algoritmo_2(int a, int b) {
    int r = 0;

    while (true) {
        r = euclide(a, b);
        cout << "r= " << r << endl;
        if (r == 0) {
            return b;
        }
        if (r > (b / 2)) {
            r = b - r;
            cout << "r= " << r << endl;
        }
        a = b;
        cout << "a= " << a << endl;
        b = r;
        cout << "b= " << b << endl << endl;
    }//fin del while
}


int algoritmo_3(int a, int b) {
    if (a < 0 || b < 0) {
        cout << "Error -> no cumple condiciones" << endl;
        return 0;
    }
    else if (b == 0) {
        return a;
    }

    cout << "Euclidemcd (" << b << " , " << euclide(a, b) << ")" << endl;

    return algoritmo_3(b, euclide(a, b));
}


int algoritmo_4(int a, int b) {
    if (conver_posi(b) > conver_posi(a)) {
        cout << "algoritmo_4(" << b << " , " << a << ")" << endl;
        return algoritmo_4(b, a);
    }

    if (b == 0) {
        cout << "a= " << a << endl;
        return a;
    }

    if ((euclide(a, 2) == 0) && (euclide(b, 2) == 0)) {
        cout << "algoritmo_4(" << a / 2 << " , " << b / 2 << ")" << endl;
        return 2 * algoritmo_4(a / 2, b / 2);
    }

    if ((euclide(a, 2) == 0) && (euclide(b, 2) != 0)) {
        cout << "algoritmo_4(" << a / 2 << " , " << b << ")" << endl;
        return algoritmo_4(a / 2, b);
    }

    if ((euclide(a, 2) != 0) && (euclide(b, 2) == 0)) {
        cout << "algoritmo_4(" << a << " , " << b / 2 << ")" << endl;
        return algoritmo_4(a, b / 2);
    }
    else {
        cout << "algoritmo_4(" << (conver_posi(a) - conver_posi(b)) / 2 << " , " << b << ")" << endl;
        return algoritmo_4((conver_posi(a) - conver_posi(b)) / 2, b);
    }
}

int algoritmo_5(int a, int b) {
    int g = 1;
    while ((euclide(a, 2) == 0) && (euclide(b, 2) == 0)) {
        a = a / 2;
        cout << "a= " << a << endl;
        b = b / 2;
        cout << "b= " << b << endl;
        g = 2 * g;
        cout << "g= " << g << endl;
    }

    while (euclide(a, 2) == 0) {
        while (euclide(a, 2) == 0) {
            cout << "Cuando a es par" << endl;
            a = a / 2;
            cout << "a= " << a << endl;
        }
        while (euclide(b, 2) == 0) {
            cout << "Cuando b es par" << endl;
            b = b / 2;
            cout << "b= " << b << endl;
        }
    }

    int t = conver_posi(a - b) / 2;
    cout << "t= (a-b)/2= " << t << endl;
    if (a >= b) {
        a = t;
        cout << "a= " << a << endl;
    }
    else {
        b = t;
        cout << "b= " << b << endl;
    }
    return (g * b);
}




int algoritmo_6(int a, int b) {
    while (a != b) {
        cout << "a= " << a << ", b= " << b << endl;
        if (a > b) {
            a = a - b;
            cout << "a= " << a << endl;
        }
        else {
            b = b - a;
            cout << "b= " << b << endl;
        }
    }
    return 0;
}
