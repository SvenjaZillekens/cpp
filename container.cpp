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

    array<int, 5> a{1,3,6,13,29};

    vector<double> v{2.0, 3.0, 5.0};

    pair<string, int> p("Anna", 123);
    cout << p.first << " (" << p.second << ")" << endl;

    tuple<int, double, string> my_tuple(2, 3.14, "Hallo");

    list<int> l = {2, 3, 6, 8, 9};

    deque<string> deq = {"a", "b", "c"};

    set<int> my_set{1, 2, 7, 0};
    unordered_set<int> my_uset{1, 2, 9, 12};

    map<int, string> my_map{{1, "Alice"}, {2, "Bob"}};
    unordered_map<int, string> my_umap{{123, "Anna"}, {124, "Ben"}};

    return 0;
}
