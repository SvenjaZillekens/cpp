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

vector<string> read_all_lines(string file_name);
void write_all_lines(string file_name, vector<string> lines);

int main() {
    auto content = read_all_lines("text.txt");
    write_all_lines("example.txt", content);
    return 0;
}

vector<string> read_all_lines(string file_name) {
    ifstream file(file_name);
    vector<string> content;

    if(file.is_open()) {
        string line;
        while (getline(file, line)) {
            content.push_back(line); // Zeile in Vektor schreiben
        }

        file.close();
    } else { cout << "Datei konnte nicht geöffnet werden." << endl; }

    return content;
}

void write_all_lines(string file_name, vector<string> lines) {
    ofstream file(file_name);

    if(file.is_open()) {
        for (auto l: lines) {
            file << l << "\n";
        }
        file.close();
    } else {
        cout << "Datei konnte nicht geöffnet werden." << endl;
    }

}
