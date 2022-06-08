#include <iostream>
#include <vector>
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
    int n, max = 1, aktuell = 1;
    string eingabe;
    getline(cin, eingabe);
    n = stoi(eingabe);
    getline(cin, eingabe);
    vector<int> days = split(eingabe, " ");

    for (int i = 1; i < n; i++){
        if (days[i] >= days[i - 1]){
            aktuell++;
            if (aktuell > max)
                max = aktuell;
        }
        else{
            aktuell = 1;
        }
    }
    cout << max << endl;

    return EXIT_SUCCESS;
}