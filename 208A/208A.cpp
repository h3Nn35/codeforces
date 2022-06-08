#include <iostream>
#include <vector>

using namespace std;

vector<string> split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
    vector<string> text;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length(); i++){
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

vector<string> splitwords(string zeichenkette){
    string original = zeichenkette, ergebnis = "";
    vector<string> text;
    int anfang = 0, vorschub = 0, i = 0;
    for (i = 0; i < original.length(); i++){
        if (vorschub > 0){
            vorschub--;
            continue;
        }
        if (original[i] == 'W' && original[i+1] == 'U' && original[i+2] == 'B'){
            ergebnis = ergebnis + " ";
            vorschub = 2;
            continue;
        }
        else
            ergebnis = ergebnis + original.substr(i, 1);
    }

    return split(ergebnis, " ");
}

int main(){
    string eingabe;
    cin >> eingabe;
    vector<string> unformatiert = splitwords(eingabe), text;

    for (int i = 0; i < unformatiert.size(); i++)
        if (unformatiert[i] != "")
            text.push_back(unformatiert[i]);

    for (int i = 0; i < text.size(); i++){
        if (text[i] != "" && i < text.size()-1)
            cout << text[i] << " ";
        else
            cout << text[i];
    }

    return EXIT_SUCCESS;
}