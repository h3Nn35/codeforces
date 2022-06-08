#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
    vector<string> text;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length() - 1; i++){
        if (original.substr(i, 1) == trennzeichen){
            text.push_back(original.substr(anfang, vorschub));
            anfang = i + 1;
            vorschub = 0;
        }
        else{
            vorschub++;
        }
    }
    text.push_back(original.substr(anfang, original.length() - anfang));
    return text;
}

int main(){
    int min = 0, max = 0, zaehler = 0, zahl;
    string zeichenkette, anzahl;
    vector<string> points;

    getline(cin, anzahl);
    getline(cin, zeichenkette);

    points = split(zeichenkette, " ");

    min = max = stoi(points[0]);

    for (int i = 0; i < points.size(); i++){
        zahl = stoi(points[i]);
        if (zahl > max){
            zaehler++;
            max = zahl;
        }
        if (zahl < min){
            zaehler++;
            min = zahl;
        }
    }

    cout << zaehler << endl;

    return EXIT_SUCCESS;
}