#include <iostream>
#include <vector>

using namespace std;

vector<int> split(string zeichenkette, string trennzeichen);

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

int main(){
    string zeichenkette = "";
    vector<int> ereignisse;
    int amount, rest, zaehler = 0, betrag = 0;
    getline(cin, zeichenkette);

    ereignisse = split(zeichenkette, " ");

    amount = ereignisse[0];
    rest = ereignisse[1];

    do{
        zaehler++;
        betrag += amount;
    }while(betrag % 10 != rest && betrag % 10 != 0);

    cout << zaehler << endl;

    return EXIT_SUCCESS;
}