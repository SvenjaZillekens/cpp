#include <iostream>
#include <array>
#include <vector>
#include <tuple>
#include <list>
#include <deque>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>

using namespace std;

int main() {
    cout << "Zusammenfassung - Container" << endl;

    // PAIR
    pair<string, int> p("Anna", 123);   // immutable / const -> unveränderbar
    cout << p.first << " (" << p.second << ")" << endl;

    // TUPLE
    tuple<int, double, string> my_tuple(2, 3.14, "Hallo");
    int first_elem_tuple = get<0>(my_tuple);

    // ARRAY
    array<int, 5> a{1,3,6,13,29};
    int elem1 = a[2]; // Zugriff auf Element an Index 2
    for (int i = 0; i < 5; ++i) { cout << a[i] << endl; } // über alle Elemente iterieren
    for (auto elem : a) { cout << elem << endl; }
    for (auto it = a.begin(); it != a.end(); ++it) { cout << *it << endl;}

    // VECTOR
    vector<double> v{2.0, 3.0, 5.0};
    double elem2 = v[1];    // Zugriff auf Element an Index 1
    double elem3 = v.at(1) 
    v[1] = 2.5;             // Element ändern an Index 1
    v.at(1) = 5.5;
    auto v_front = v.front();   // erstes Element
    auto v_back = v.back();     // letztes Element
    v.push_back(6.5);   // Hinzufügen eines Elements am Ende
    v.pop_back();       // Entfernen des letzten Elements
    for (auto i: v) { cout << i << endl; }  // iterieren
    for (size_t i = 0; i < v.size(); ++i) { cout << v[i] << endl; } 
    v.clear();  // Vektor leeren

    // Iteratoren
    for (auto it = v.begin(); it != v.end(); ++it) { cout << *it << endl; } // iterieren
    auto it5 = find(v.begin(), v.end(), 5); // Element suchen
    if (it5 != v.end()) v.insert(it5, 23.9);// falls Element vorhanden, Wert ändern

    // LIST
    list<int> l = {2, 3, 6, 8, 9};
    for (auto elem : l) { cout << elem << endl; } // über alle Elemente iterieren
    l.push_back(11); // Element hinten hinzufügen
    l.push_front(1); // Element vorne hinzufügen
    l.pop_front();   // erstes Element entfernen
    l.pop_back();    // letztes Element entfernen
    auto l_size = l.size();

    // DEQUE
    deque<string> deq = {"a", "b", "c"};
    string deq_elem = deq[0];
    // hinzufügen, entfernen, size und iterieren wie list

    // SET // UNORDERED_SET
    set<int> my_set{1, 2, 7, 0};    // ohne Indexierung !
    for (int elem : my_set) { cout << elem << endl; }
    my_set.insert(6); // Element hinzufügen
    my_set.erase(7);  // Element entfernen
    cout << my_set.size() << endl; // size
    if (my_set.find(2) != my_set.end()) cout << "Element 2 existiert" << endl; // Element suchen

    unordered_set<int> my_uset{1, 2, 9, 4};
    for (int elem : my_uset) { cout << elem << endl; }

    // MAP // UNORDERED_MAP
    map<int, string> my_map{{1, "Alice"}, {2, "Bob"}};
    cout << my_map.size() << endl; // size
    string value = my_map[2]; // Zugriff auf Value von Key = 2
    auto it2 = my_map.find(2);// Element suchen
    for (auto elem : my_map) { cout << elem.first << ": " << elem.second << endl;}
    my_map[4] = "Dora"; // key-value hinzufügen
    my_map.erase(2);    // Eintrag mit key = 2 entfernen

    unordered_map<int, string> my_umap{{123, "Anna"}, {124, "Ben"}};

    return 0;
}