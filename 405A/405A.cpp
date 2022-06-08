#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

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

int main()
{
    string eingabe;
    getline(cin, eingabe);
    int n = stoi(eingabe);
    getline(cin, eingabe);
    vector<int> spalten = split(eingabe, " ");

    sort(spalten.begin(), spalten.end());

    cout << spalten[0];

    for (int i = 1; i < n; i++)
        cout << " " << spalten[i];

    return EXIT_SUCCESS;
}