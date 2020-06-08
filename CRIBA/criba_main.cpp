#include <iostream>
#include <vector>

using namespace std;

int main() {
    vector<int> criba_E;
    long tam;
    cin >> tam;
    criba_E.push_back(2);
    for (int i = 3; i < tam + 1; i += 2) {
        criba_E.push_back(i);
    }
    int e = 1;
    while (criba_E[e] * criba_E[e] < tam) {
        for (int i = e + 1; i < criba_E.size(); i++) {
            if (criba_E[i] % criba_E[e] == 0) {
                criba_E.erase(criba_E.begin() + i);
            }
        }
        e++;
    }
    for (int i = 0; i < criba_E.size(); i++) {
        cout << criba_E[i] << " ";
    }
}