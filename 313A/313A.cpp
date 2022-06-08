#include <iostream>

using namespace std;

string substring(string text, int anfang, int ende){
    int laenge = text.length();
    string ergebnis = "";

    ergebnis = text.substr(anfang, ende - anfang + 1);

    return ergebnis;
}

int main(){
    string eingabe, eingabea, eingabeb;
    int n, a, b;
    n = 12;
    cin >> n;
    eingabe = to_string(n);

    if (n >= 0){
        cout << n;
        return EXIT_SUCCESS;
    }

    eingabea = substring(eingabe, 0, eingabe.length()-2);
    a = stoi(eingabea);
    eingabeb = substring(eingabe, 0, eingabe.length()-3) + eingabe.substr(eingabe.length()-1, 1);
    b = stoi(eingabeb);

    if (a > b)
        cout << a;
    else
        cout << b;
    
    return EXIT_SUCCESS;
}