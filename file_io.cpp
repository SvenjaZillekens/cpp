#include <iostream>
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

int main() {
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
    return 0;
}