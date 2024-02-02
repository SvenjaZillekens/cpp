#include <iostream>
using namespace std;

// Beispielklasse
class koordinaten {
public:
    double x_;
    double y_;

    // default ctor
    koordinaten() = default;

    // default dtor
    ~koordinaten() = default;

    // ctor
    koordinaten(double x, double y) : x_{x}, y_{y} {
        cout << "ctor()" << endl; 
    }

    // copy ctor
    koordinaten(const koordinaten &koord) : x_{koord.x_}, y_{koord.y_} {}

    // getter
    double get_x() const { return x_; }
    double get_y() const { return y_; }

    // setter
    void set_x(const double x) { this->x_ = x; }
    void set_y(const double y) { this->y_ = y; }
};

ostream &operator<<(ostream &os, const koordinaten &k) {
    os << "(" << k.x_ << "|" << k.y_ << ")";
    return os;
}

// Beispielklasse als Template
template <typename T>
class koordinatenT {
public:
    T x_;
    T y_;

    // default ctor
    koordinatenT() = default;

    // default dtor
    ~koordinatenT() = default;

    // ctor
    koordinatenT(T x, T y) : x_{x}, y_{y} {
        cout << "ctor()" << endl; 
    }

    // copy ctor
    koordinatenT(const koordinatenT &koord) : x_{koord.x_}, y_{koord.y_} {}

    // getter
    T get_x() const { return x_; }
    T get_y() const { return y_; }

    // setter
    void set_x(const T x) { this->x_ = x; }
    void set_y(const T y) { this->y_ = y; }
};

template<typename T>
ostream &operator<<(ostream &os, const koordinatenT<T> &k) {
    os << "(" << k.x_ << "|" << k.y_ << ")";
    return os;
}

int main() {
    // normal
    koordinaten k1;
    cout << k1 << endl;
    koordinaten k2(2.5, 3.9);
    cout << k2 << endl;
    koordinaten k3(k2);
    cout << k3 << endl;

    // template
    koordinatenT<int> kt1(2, 7);
    cout << kt1 << endl;
    koordinatenT<float> kt2(3.1415f, 1.2345f);
    cout << kt2 << endl;

    return 0;
}