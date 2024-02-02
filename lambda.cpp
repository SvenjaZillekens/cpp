#include <iostream>
#include <functional>
using namespace std;

int main() {
    auto plus = [](int x, int y) {return x+y; };
    cout << plus(1, 4) << endl;

    auto mal = [](auto a, auto b) { return a*b; };
    cout << mal(3, 7) << endl;

    auto doppelt = [](double x) -> double { return x*2; };
    cout << doppelt(3.5) << endl;

    int m{3};
    auto plus_m = [=](int n) { return n + m; };
    cout << plus_m(4) << endl;

    auto plus_refm = [&m](int n) { return n + m; };
    cout << plus_refm(4) << endl;

    return 0;
}