#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitString{
    private:
        vector<string> text;
    public:
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

int main(){
    SplitString text;
    string eingabe, eingabe1, spitzenreiter;
    int t, max = 0, anzahl = 1;
    getline(cin, eingabe1);
    getline(cin, eingabe);
    t = stoi(eingabe1);

    for (int i = 0; i < t - 1; i++){
        text.add(eingabe.substr(i, 2));
    }

    text.sortieren();

    if (text.size() > 1){
        for (int i = 0; i < text.size() - 1; i++){
            if (text[i] == text[i + 1])
                anzahl++;
            else
                anzahl = 1;
            
            if (anzahl > max){
                max = anzahl;
                spitzenreiter = text[i];
            }
        }
        cout << spitzenreiter << endl;
    }
    else
        cout << text[0] << endl;
    
    return EXIT_SUCCESS;
}