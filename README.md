# Cheat Sheet C++

## Kapitel 0x01

### Unterkapitel a

* Zusammenfassung des Unterkapitels a

### Unterkapitel b

* Zusammenfassung des Unterkapitels b

### Unterkapitel c

* Zusammenfassung des Unterkapitels c



## Kapitel 0x02

### Unterkapitel a

* Zusammenfassung des Unterkapitels a

### Unterkapitel b

* Zusammenfassung des Unterkapitels b

### Unterkapitel c

* Zusammenfassung des Unterkapitels c




## Kapitel 0x03 - Klassen

### Beispielklasse (Vorlage)

class address {
private:            // default
    int id_;
public:
    // default ctor
    address() : id_{0} {
        cout << "New Address: id = 0" << endl;
    }

    // ctor with value
    address(int id) : id_{id} {
        cout << "New Address: id = " << id << endl;
    }

    // copy ctor
    address(const address& a) : id_{a.id_+1} {
        cout << "New Address: id = " << id_ << endl;
    }

    dtor
    ~address() { cout << "dtor(): id = " <<  id_ << endl; }

    // getter
    int get_id() const { return id_; }

    // setter
    void set_id(const int id) { this->id_ = id; }

};

// Objekte in main erstellen:
address a0;     // default ctor wird aufgerufen
address a1(1);  // ctor with value
address a2(a1); // copy ctor
a2.set_id(5);               // set new id
int new_id = a2.get_id();   // get new id


// Operator überladen
ostream &operator<<(ostream &os, const address &a) {
    os << "Adresse mit id=" << a.id();
    return os;
}

## Kapitel 0x04 - Generics = Template

### 


## Kapitel 0x05 - Pointer I

    int n{15};      // lokale Variable auf Stack, &n ist Adresse im Speicher
    int n{31};      // wie n
    int* p{nullprt};// Zeiger auf int, der mit nullptr initialisiert wird
    p = &n;         // Wert von p auf Adresse von n setzen
    cout << *p;     // Dereferenzierung; Wert von n ausgeben
    p = &m;         // Zeiger zeigt jetzt auf m
    *p = 3;         // Wert von m über Zeiger verändern

    int** pp = &p;  // Zeiger auf Zeiger von int
    cout << **pp;   // Mehrfach-Dereferenzierung

* math:
    int n{1};
    int* pn{&n};
    ++pn;       // Pointer um 4 (Größe von int) Bytes erhöhen

    void* p;    // typlos; kann jeden Zeiger speichern
    // ++p;     // nicht definiert!

* array

    const int dim = 3;
    int a[dim]={1,2,3};
    int* p;
    p = &a[0];          // Zeiger auf erstes Feld-Element
    p = a;              // Zeiger auf Adresse der ersten Elements
    for (size_t i=0; i<dim; ++i) { // über Feld mit Zeiger p+i
        cout << "p+ " << i << "=" << p+i << "," << *(p+i);
    }

* call-by-value, call-by-ref
    - call-by-value: Parameter werden kopiert; Änderungen in einer Funktion wirken sich nicht auf den Originalparam aus
    - call-by-ref: Originalparams werden verändert
        Referenzen -> Aliasse
        Zeiger -> über Zeiger sind auch Originalparams im Zugriff

* illegal: 
    - Wert von n2 über Zeiger auf n1 verändern
    int n1{23};
    int n2{42};
    int* pn{&n1};
    *(pn-1)=123;



## Kapitel 0x06 - Pointer II

### a: new

* new, delete: 
    int n{42};
    int* local_ptrn{&n};         // Zeiger auf n, lokal auf Stack
    int* heap_ptrn{new int{23}}; // Zeiger auf int-Variable, die auf Heap liegt
    heap_ptrn = new int{123};    // neue int-Variable auf Heap; alte Variable nicht mehr erreichbar -> Speicherleck
    delete heap_ptrn;            // gesamten Speicher, der vorher reserviert wurde, frei geben

    int* a = new int[n];         // Feld von ints er Länge n; Pointer auf erste Adresse (im Heap)
    cout << a[3];                // Zeiger wie ein Feld benutzen
    delete[] a;                  // mehrere Elemente freigeben

* mehrere Zeiger deklarieren
    int* a, b   // Zeiger a, int b
    int *a, *b  // Zeiger a, Zeiger b

* friend class
    // Klasse darf auf alle privaten Member zugreifen

* unique pointer
    using std::unique_ptr;      // Speicher freigeben, wenn Pointer out-of-scope -> Speicherlecks automatisch vermeiden (z.B. wenn Exception fliegt)
    using std::make_unique;     // korrekter Weg, um unique_ptr zu erzeugen

    unique_ptr<pair> p1 = make_unique<pair>(1,2);
    unique_ptr<pair> p2;
    p2 = move(p1);      // Verantwortung von p1 auf p2 transferieren; p1 ist danach leer
    p2.reset();         // Zeiger freigeben

### b: const pointer

int i{1};                    // normaler int        : Wert veränderbar
int* pi = &i;                // Zeiger auf int      : Wert und Zeiger veränderbar
const int ci{2};             // const int           : Wert konstant
const int* pci = &ci;        // Zeiger auf const int: Wert konstant, Zeiger veränderbar

int* const pci = &i;         // const Zeiger auf int : Wert veränderbar, Zeiger konstant
const int* const pcic = &ci; // const Z auf const int: Wert und Zeiger konstant

### c: C-Strings
const char* s = "Text"; // endet mit 0-Byte ’\0’
for (const char* p=s; (*p); ++p) {  // Zeiger wie Feld durchlaufen; Schleife endet bei '\0’
    cout << " " << *p;              // jedes Zeichen einzeln ausgeben -> "T", "e", "x", "t"
    cout << " " << p;               // Ausgabe ab i-tem Zeichen -> "Text", "ext", "xt", "t"
}

const int dim{4};
const char *arr[dim] = {"Dies", "ist", "ein", "Satz"}; // Feld aus Zeigern


## Kapitel 0x07 - Operatoren

### a: lang

* [[nodiscard]] int my_funct(int n) { return n*2; }
    // Warnung, wenn Funktion mit return Wert aufgerufen wird, der nicht genutzt wird

### b: Operator-Überladung -> 0x07b

* & Operator (Achtung!)
address* operator&() const { return nullptr; } // zur Klasse address
address* pa = &a; // nullptr (unerwartet!)

* = Operator
address& operator=(const address& a) {
    cout << "this-id=" << id << ", a.id=" << a.id << endl;
    return *this;
}
address a2=a1; // wie copy-ctor

* += Operator // member
    klasse& operator+=(const klasse& k) {
        return *this;
    }

* + Operator
// global:
klasse operator+(const klasse& k1, const klasse& k2) {
    cout << "+" << endl;
    klasse res{k1};
    return res+=k2;
}

* << Operator (friend)
    friend ostream& operator<<(ostream& os, const klasse& k) {
        os << k.variable;
        return os;
    }

* () Operator // member
double operator()(double x) const {
    if (i >= dim) { throw invalid_argument("index too large"); }
    return coeffs[i];
}

* [] Operator // member
double operator[](size_t i) const {
    return coeffs[i];
}

## Kapitel 0x08 - Polymorphie

### a: einfachvererbung
class Fahrzeug {                // Basisklasse
public:
    Fahrzeug() = default;
    void fahren() { cout << "Fahrzeug fährt"; }
    virtual void parken() { cout << "Fahrzeug parkt"; }
};

class Auto : public Fahrzeug {  // abgeleitete Klasse
public:
    Auto() = default;
    void hupen() { cout << "Hupe tut's"; }
    void parken() override { cout << "Auto parkt"; }
}

int main() {
    Auto meinAuto();
    meinAuto.fahren();
    meinAuto.hupen();
}

* virtual: abgeleitete Klasse kann Funktion aus Basisklasse überschreiben

### b: abstrakte Klassen
* pure virtual: (wie Interface)
// in Basisklasse:
virtual void parken() = 0;
// in abgel. Klasse wie vorher

* virtual dtor -> avoid memory leak

### c: Mehrfachvererbung
class Fahrzeug { ... };
class Radio {
public:
    Radio() = default;
    void radioAn() { cout << "Radio läuft."; }
};
class Auto : public Fahrzeug, public Radio { ... };

int main() {
    Auto meinAuto();
    meinAuto.fahren();
    meinAuto.radioAn();
    meinAuto.hupen();
    return 0;
}


## Kapitel 0x09 - Specialize

### a: Specialize -> C++20
template <typename T1, typename T2> // generelle Template Klasse mit Datentyp T1 und T2
struct pair_special { ... }

template <typename T2>  // Spezialisierung: erster Parameter int, zweiter T2
struct pair_special<int,T2> { ... }

template <typename T1>  // Spezialisierung: beide Datentypen identisch
struct pair_special<T1,T1> { ... }

template<>  // Spezialisierung: erster Parameter int, zweiter int
struct pair_special<int,int> { ... }

### b: Smart-Pointer

#include <memory>
using std::weak_ptr;
using std::make_shared;

* shared pointer
shared_ptr<MyClass> sharedPtr = make_shared<MyClass>(42);

// Erstellen eines weiteren shared_ptr, der auf dasselbe Objekt zeigt
shared_ptr<MyClass> sharedPtr2 = sharedPtr;

    - shared_ptr automatisch freigeben, wenn der letzte shared_ptr das Objekt freigibt


* weak pointer
shared_ptr<MyClass> sharedPtr = make_shared<MyClass>(42);
weak_ptr<MyClass> weakPtr = sharedPtr;  // weak_ptr aus shared_ptr erstellen


## Kapitel 0x0a - 

### a: Lambda
* sort
array<int,10> a = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3}; 
sort(a.begin(), a.end());   // aufsteigend sortiert

bool even_odd(int a, int b) { return (a%2==b%2) ? (a<=b) : (a%2==0); }
sort(a.begin(), a.end(), even_odd); // gerade Zahlen aufsteigend, ungerade Zahlen aufsteigend

sort(a.begin(), a.end(), std::greater<>()); // absteigend

sort(a.begin(), a.end(), [](int a, int b) -> bool { return a <= b; }); // lambda ausdruck -> aufsteigend

* simple
auto less = [](int a, int b) -> bool { return a < b; };

auto plus2 = [](int n) -> int { return n + 2; }; // anstelle -> int{} geht auch auto{} oder gar nichts
int n{7};
plus2(n);

* functions
auto l4a = [](double x) { return x*x*x*x; };
function_t l4b = [](double x) -> double {return x*x*x*x;};
double evalf(function_t f, double x) { return f(x); }
evalf(l4a, 1.0);
evalf(l4b, 1.0);

### b: Algorithmen
* non-modifying sequence operations
array<int,11> a = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3, 5};
std::all_of(a.begin(), a.end(), [](int i){return i>=0;})
std::any_of(...)
std::none_of(...)
std::count(a.begin(), a.end(), 1) // count all '1' in a
std::count_if(,, x)               // count > x

int sum{0};
std::for_each(a.begin(), a.end(), [&sum](int i) {sum+=i;});

* modifying sequence operations
array<int,11> a = {5, 7, 4, 2, 8, 6, 1, 9, 0, 3, 5};
vector<int> v(5);

std::fill(v.begin(), v.end(), 11);      // fill vector with values
std::copy_n(a.begin()+2, 5, v.begin()); // copy 5 elements from a at position 2
std::generate(v.begin(), v.end(),
    [&f1,&f2] () { int f{(f2>0)?f1+f2:1}; f1=f2; f2=f; return f; });

std::replace(v.begin(), v.end(), 1, -1);    // replace individual elements
std::replace_if(v.begin(), v.end(), [](int i){return (i>0);}, -2); // replace elements according to conditions

std::reverse(v.begin(), v.end());

* sort
std::is_sorted(a.begin(), a.end() ) // bool
auto until_elem = std::is_sorted_until(a.begin(), a.end() ); // 
auto min_elem = std::min_element(a.begin(), a.end());
auto max_elem = std::max_element(a.begin(), a.end());

* numerics


### c: Stream
* file io
* #include <iostream>
#include <string>
#include <fstream>
#include <vector>
using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::ifstream;
using std::ofstream;
using std::vector;

ifstream inputFile("example.txt"); // Dateiname zum Lesen
vector<string> lines;

if (inputFile.is_open()) {
    string line;

    while (getline(inputFile, line)) { // Datei Zeile für Zeile lesen
        cout << line << endl;
        lines.push_back(line); // Zeile in Vektor schreiben
    }

    inputFile.close(); // Datei schließen
} else {
    cout << "Datei konnte nicht geöffnet werden." << endl;
}

* string io
*    #include <iostream>
    #include <string>
    #include <fstream>
    #include <sstream>
    #include <vector>
    #include <iomanip>
    using std::cout;
    using std::endl;
    using std::ostream;
    using std::string;
    using std::ifstream;
    using std::ofstream;
    using std::vector;
    using std::istringstream;
    using std::ostringstream;

string lines = "S1 123\nS2 456";
istringstream is1(lines);
if (is1) {
    string line;
    while (getline(is1,line)) { 
        cout << "line: '" << line << "'" << endl;
        istringstream sline(line);
        string s;
        int n;
        sline >> s >> n;
        cout << "s:" << s << ", n:" << n << endl;
    }
}

## Kapitel 0x0b - Threads

### a: Threads
#include <thread>
void work(int sleep) { ... }

thread tpaul(work, 500);
thread tlisa(work, 1000);
thread thans(work, 100);

tpaul.join();
thans.join();
tlisa.join();

### b: mutex
mutex mutex_sum;
work_a(...) {
    for (auto i=0, i<n; ++i) {
        mutex_sum.lock();       // prevent 2 Threads from entering this code area at the same time
        // do something
        mutex_sum.unlock()      // wenn Exception während do something wird mutex nicht mehr freigegeben
    }
}

work_b(...) {
    for (auto i=0, i<n; ++i) {
        lock_guard<mutex> lk(mutex_sum); // object that releases mutex at the end of its lifetime -> mutex will always be released
        // do something
    }
}

### c: future promise

## Kapitel 0x0c - 

### a: enum
= global const ints
enum COLOR { RED, GREEN, BLUE}; // = 0, 1, 2
enum SYMBOL { CROSS=1, SPADE, HEART=11, DIAMOND }; // 1, 2, 11, 12

### b: type conversions
int i{23};
long l{i}; // implizit