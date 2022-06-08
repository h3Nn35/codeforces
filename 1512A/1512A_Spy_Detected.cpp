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

int main(){
    int anzahl, anzahltests, a, b, c;
    string eingabe;
    vector<int> numbers, result;

    getline(cin, eingabe);
    anzahltests = stoi(eingabe);

    for (int i = 0; i < anzahltests; i++){
        getline(cin, eingabe);
        anzahl = stoi(eingabe);
        getline(cin, eingabe);
        numbers = split(eingabe, " ");
        a = numbers[0];
        b = numbers[1];
        for (int x = 2; x < anzahl; x++){
            c = numbers[x];
            if (a == b && a == c && b == c)
                continue;

            if (a == b){
                result.push_back(x+1);
                break;
            }

            if (a == c){
                result.push_back(2);
                break;
            }

            if (b == c){
                result.push_back(1);
                break;
            }
        }
    }   

    for (int i = 0; i < anzahltests; i++)
        cout << result[i] << endl;

    return EXIT_SUCCESS;
}