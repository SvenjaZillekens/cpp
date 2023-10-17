#include <iostream>
#include <math.h>
using namespace std;

void isPrim(int n);

int main() {
    std::cout << "Pine Point" << std::endl;

    int n;
    cout << "Please enter a number: ";
    cin >> n;
    if (n < 2) { cout << "Cannot get primes from numbers smaller than 2." << endl; return 0;}

    isPrim(n);

    return 0;
}

void isPrim(int n) {
    // initialize an array with false
    bool gestrichen[n];
    cout << "Hallo aus der Funktion.";
    for (int i = 2; i < n; i++) {
        gestrichen[i] = false;
        cout << gestrichen[i];
    }

    cout << int(sqrt(n)) << endl;

    for (int j = 2; j <= int(sqrt(n))+1; j++) {
        if (!gestrichen[j]) {
            // j ist primzahl
            cout << n << ", ";

            // alle Vielfachen von j sind nicht prim -> streichen
            for (int k = j*j; k < n; k+=j) {
                gestrichen[k] = true;
            }
        }
    }

    // alle Primzahlen ausgeben
    for (int i = 2; i < n; i++) {
        if (!gestrichen[i]) { cout << i << ", ";}
    }
}
