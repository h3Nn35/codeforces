#include <iostream>
#include <vector>

using namespace std;

vector<int> split(string zeichenkette, string trennzeichen);

int main(){
    string anzahl = "", zeichenkette = "";
    vector<int> ereignisse;
    int untreated = 0, aktuell = 0, vorgang = 0, police = 0;

    getline(cin, anzahl);
    getline(cin, zeichenkette);

    ereignisse = split(zeichenkette, " ");

    for (int i = 0; i < stoi(anzahl); i++){
        if(ereignisse[i] > 0)
            police += ereignisse[i];
        else{
            if(police == 0)
                untreated++;
            else
                police--;
        }
    }

    cout << untreated << endl;

    return EXIT_SUCCESS;
}

vector<int> split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
    vector<int> text;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length() - 1; i++){
        if (original.substr(i, 1) == trennzeichen){
            text.push_back(stoi(original.substr(anfang, vorschub)));
            anfang = i + 1;
            vorschub = 0;
        }
        else{
            vorschub++;
        }
    }
    text.push_back(stoi(original.substr(anfang, original.length() - anfang)));
    return text;
}