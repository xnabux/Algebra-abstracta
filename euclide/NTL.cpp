#include <iostream>
#include<time.h>
#include <NTL/ZZ.h>

using namespace std;
using namespace NTL;


ZZ conver_posi(ZZ a);
ZZ euclide(ZZ a, ZZ b);
ZZ algoritmo_1(ZZ a, ZZ b);
ZZ algoritmo_2(ZZ a, ZZ b);
ZZ algoritmo_3(ZZ a, ZZ b);
ZZ algoritmo_4(ZZ a, ZZ b);
ZZ algoritmo_5(ZZ a, ZZ b);
ZZ algoritmo_6(ZZ a, ZZ b);
ZZ algoritmo_7(ZZ a, ZZ b);


int main() {
    clock_t t, t2;
    t = clock();
    ZZ a = conv<ZZ>("9654684654654684687984684654654321324654684987984165468465654646849889785132165498986465498463649864563546846535468486654987987987687684646543546847687879879874354354355132134648798796165198198495631354897986454649864649865468744685335168549865498649865416531354986846456465489684684654654535");
    ZZ b = conv<ZZ>("6984849848646543135165468465465465468498468465435135135132131654654646846884646468468846846465465465461355131656486646654313216546546848989446554354897987987986846543131321354654687987987498498468465465413513546546898747987684684654354684864646868465464897988735435465484684351835438468449876");
    //euclide(a, b);
    a = algoritmo_6(a, b);
    cout << "MCD= " << a << endl;
    t = clock() - t;
    cout << "\nTIEMPO QUE TARDO EL ALGORITMO 1: " << float(t) / CLOCKS_PER_SEC << " segundos\n";

}


ZZ euclide(ZZ a, ZZ b) {

    if (a >= 0) {
        return a - (b * (a / b));
    }
    else {
        return a - (((a / b) - 1) * b);
    }

}


ZZ conver_posi(ZZ a) {
    if (a < 0) {
        a = a * -1;
    }
    return a;
}

ZZ algoritmo_1(ZZ a, ZZ b) {
    ZZ r ;
    while (true) {
        r = euclide(a, b);
        //cout << "r= " << r << endl;
        if (r == 0) {
            return b;
        }
        else {
            a = b;
            //cout << "a= " << a << endl;
            b = r;
            //cout << "b= " << b << endl << endl;
        }
    }//fin while
}

ZZ algoritmo_2(ZZ a, ZZ b) {
    ZZ r ;

    while (true) {
        r = euclide(a, b);
       // cout << "r= " << r << endl;
        if (r == 0) {
            return b;
        }
        if (r > (b / 2)) {
            r = b - r;
           // cout << "r= " << r << endl;
        }
        a = b;
        //cout << "a= " << a << endl;
        b = r;
        // << "b= " << b << endl << endl;
    }//fin del while
}


ZZ algoritmo_3(ZZ a, ZZ b) {
    if(b==0){
        return a;
    }
    cout<<" a "<<a<<" b "<<b<<endl;
    return algoritmo_3(b, euclide(a, b));
}


ZZ algoritmo_4(ZZ a, ZZ b) {
    ZZ x(2);
    if (conver_posi(b) > conver_posi(a)) {
       // cout << "algoritmo_4(" << b << " , " << a << ")" << endl;
        return algoritmo_4(b, a);
    }

    if (b == 0) {
       // cout << "a= " << a << endl;
        return a;
    }

    if ((euclide(a, x) == 0) && (euclide(b, x) == 0)) {
       // cout << "algoritmo_4(" << a / 2 << " , " << b / 2 << ")" << endl;
        return 2 * algoritmo_4(a / 2, b / 2);
    }

    if ((euclide(a, x) == 0) && (euclide(b, x) != 0)) {
       // cout << "algoritmo_4(" << a / 2 << " , " << b << ")" << endl;
        return algoritmo_4(a / 2, b);
    }

    if ((euclide(a, x) != 0) && (euclide(b, x) == 0)) {
       // cout << "algoritmo_4(" << a << " , " << b / 2 << ")" << endl;
        return algoritmo_4(a, b / 2);
    }
    else {
       // cout << "algoritmo_4(" << (conver_posi(a) - conver_posi(b)) / 2 << " , " << b << ")" << endl;
        return algoritmo_4((conver_posi(a) - conver_posi(b)) / 2, b);
    }
}

ZZ algoritmo_5(ZZ a, ZZ b) {
    ZZ g(1);
    ZZ x(2);
    ZZ t;
    while ((euclide(a, x) == 0) && (euclide(b, x) == 0)) {
        a = a / 2;
        //cout << "a= " << a << endl;
        b = b / 2;
      // cout << "b= " << b << endl;
        g = 2 * g;
       // cout << "g= " << g << endl;
    }

    while (a!=0) {
        while (euclide(a, x) == 0) {
           // cout << "Cuando a es par" << endl;
            a = a / 2;
         //   cout << "a= " << a << endl;
        }
        while (euclide(b, x) == 0) {
          //  cout << "Cuando b es par" << endl;
            b = b / 2;
          // cout << "b= " << b << endl;
        }
    }

    t = conver_posi(a - b) / 2;
    cout << "t= (a-b)/2= " << t << endl;
    if (a >= b) {
        a = t;
        //cout << "a= " << a << endl;
    }
    else {
        b = t;
        //cout << "b= " << b << endl;
    }
    return (g * b);
}




ZZ algoritmo_6(ZZ a, ZZ b) {
    while (a != b) {
       // cout << "a= " << a << ", b= " << b << endl;
        if (a > b) {
            a = a - b;
            //cout << "a= " << a << endl;
        }
        else {
            b = b - a;
            //cout << "b= " << b << endl;
        }
        return a;

    }
}




ZZ algoritmo_7(ZZ a, ZZ b) {
    while (a != b)
    {
        if (a > b)
        {
            //cout << "a y b son: " << a << "-" << b << "\n";
            a = a - b;//cout<<a<<"-"<<b<<endl;
        }
        else
        {
            b = b - a;
            //cout << "a y b son: " << a << "-" << b << "\n";
        }

    }
    return a;
}
/*

*/
