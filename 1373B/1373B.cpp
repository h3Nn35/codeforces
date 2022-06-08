#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitString{
    private:
        vector<string> text;
    public:
        void split(string zeichenkette);
        void split(string zeichenkette, string trennzeichen);
        vector<string> gettext();
        void add(string eingabe);
        void ausgabe();
        void sortieren();
        void operator=(vector<string> other);
        int size();
        string operator[](int index);
        void doppelteEntfernen();
        void einzelnesEntfernen(int index);
};

void SplitString::split(string zeichenkette){
    text.clear();
    string original = zeichenkette;
    for (int i = 0; i < original.length(); i++)
        text.push_back(original.substr(i, 1));
}

void SplitString::einzelnesEntfernen(int index){
    text.erase(text.begin()+index);
}

void SplitString::doppelteEntfernen(){
    int i = 0, laenge = size();
    sortieren();
    while (i < laenge)
    {
        if (text[i] == text[i + 1]){
            einzelnesEntfernen(i+1);
        }
        else
            i++;
    }
}

void SplitString::add(string eingabe){
    text.push_back(eingabe);
}

void SplitString::operator=(vector<string> other){
    text.clear();
    for (int i = 0; i < other.size(); i++)
        text.push_back(other[i]);
}

void SplitString::sortieren(){
    sort(text.begin(), text.end());
}

string SplitString::operator[](int index){
    return text[index];
}

int SplitString::size(){
    return text.size();
}

vector<string> SplitString::gettext(){
    return text;
}

void SplitString::ausgabe(){
    for (int i = 0; i < text.size(); i++){
        cout << text[i] << endl;
    }
}

void SplitString::split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
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
}

int minimal(int zahl1, int zahl2){
    if (zahl1 < zahl2)
        return zahl1;
    else if (zahl2 < zahl1)
        return zahl2;
    else if (zahl1 == zahl2)
        return zahl1;
    else
        return 0;
}

int main(){
    int t, zahleins, zahlnull, kleinstes;
    SplitString tests, ergebnis;
    string eingabe = "1";
    getline(cin, eingabe);
    t = stoi(eingabe);
    for (int i = 0; i < t; i++){
        eingabe = "01";
        getline(cin, eingabe);
        tests.split(eingabe);
        zahleins = 0;
        zahlnull = 0;
        for (int j = 0; j < tests.size(); j++)
            if (tests[j] == "1")
                zahleins++;
            else
                zahlnull++;
        kleinstes = minimal(zahleins, zahlnull);
        if (kleinstes % 2 == 0)
            ergebnis.add("NET");
        else
            ergebnis.add("DA");
    }
    
    ergebnis.ausgabe();

    return EXIT_SUCCESS;
}