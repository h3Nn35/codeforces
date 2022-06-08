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
        // int finde(char zeichen);
};

// int SplitString::finde(char zeichen){
    
// }

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
    string direction, eingabe, ausgabe2 = "", zeile1, zeile2, zeile3;
    char zeichen;
    int rl, position;
    SplitString ausgabe;
    cin >> direction;
    cin >> eingabe;

    if (direction == "" || eingabe == "")
        return EXIT_SUCCESS;

    if (direction == "L")
        rl = 1;
    else
        rl = -1;

    zeile1 = "qwertyuiop";
    zeile2 = "asdfghjkl;";
    zeile3 = "zxcvbnm,./";

    for (int i = 0; i < eingabe.length(); i++){
        zeichen = eingabe[i];
        if (zeile1.find(zeichen) != string::npos){
            position = zeile1.find(zeichen);
            eingabe[i] = zeile1[position+rl];
        }
        else if (zeile2.find(zeichen) != string::npos){
            position = zeile2.find(zeichen);
            eingabe[i] = zeile2[position+rl];
        }
        else if (zeile3.find(zeichen) != string::npos){
            position = zeile3.find(zeichen);
            eingabe[i] = zeile3[position+rl];
        }

    }

    cout << eingabe;

    return EXIT_SUCCESS;
}