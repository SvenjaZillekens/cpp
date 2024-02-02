#include <iostream>
#include <vector>
using namespace std;


ostream &operator<<(ostream &os, const vector<int> &v) {
    os << "(";
    for (auto &val : v) {
        os << val << " ";
    }
    os << ")";
    return os;
}

// Template Operator-Überladung
template<typename T>
ostream &operator<<(ostream &os, const vector<T> &k) {
    os << "(";
    for (auto &val : v) {
        os << val << " ";
    }
    os << ")";
    return os;
}

int main() {

    vector<int> v{1, 3, 5, 10, 29, 46};
    cout << v << endl; 

}