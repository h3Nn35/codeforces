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
    int anzahltests, i, a, b, c, moves;;
    string anzahl, zeile;
    vector<string> tests, gesplittet;

    getline(cin, anzahl);

    anzahltests = stoi(anzahl);

    for (i = 0; i < anzahltests; i++){
        getline(cin, zeile);
        tests.push_back(zeile);
    }

    for (i = 0; i < anzahltests; i++){
        moves = 0;
        zeile = tests[i];
        gesplittet = split(zeile, " ");
        a = stoi(gesplittet[0]);
        b = stoi(gesplittet[1]);

        if (a == b){
            cout << moves << endl;
            continue;
        }

        if (a > b){
            c = a;
            a = b;
            b = c;
        }

        c = b - a;

        c = c - c % 10;

        moves = c / 10 + 1;

        cout << moves << endl;
        
    }

    return EXIT_SUCCESS;
}
