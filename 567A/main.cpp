#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitInteger{
private:
    vector<int> zahlen;
public:
    void split(string zeichenkette);
    void split(string zeichenkette, string trennzeichen);
    void splitby(string zeichenkette, char trennzeichen);
    void leeren();
    vector<int> getZahlen();
    void add(int eingabe);
    void add(string eingabe);
    void ausgabe();
    void sortieren();
    void operator=(vector<int> other);
    int size();
    int operator[](int index);
    string operator=(string eingabe);
    int operator=(int eingabe);
    int getIndexOf(int zahl);
    int getPositionBiggest();
    int max();
    int min();
    void einzelnesEntfernen(int index);
};

int SplitInteger::operator=(int eingabe){
    split(to_string(eingabe));
    return eingabe;
}

string SplitInteger::operator=(string eingabe){
    split(eingabe);
    return eingabe;
}

int SplitInteger::getIndexOf(int zahl){
    for (int i = 0; i < size(); i++)
        if (zahlen[i] == zahl)
            return i;
    return -1;
}

int SplitInteger::getPositionBiggest(){
    return getIndexOf(max());
}

void SplitInteger::add(string eingabe){
    if (eingabe != "")
        add(stoi(eingabe));
}

void SplitInteger::splitby(string zeichenkette, char trennzeichen){
    string original = zeichenkette;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length(); i++){
        if(original[i] == trennzeichen){
            add(original.substr(anfang, vorschub));
            anfang = i;
            vorschub = 1;
        }
        else{
            vorschub++;
        }
    }
    zahlen.push_back(stoi(original.substr(anfang, original.length() - anfang)));
}

void  SplitInteger::einzelnesEntfernen(int index){
    zahlen.erase(zahlen.begin() + index);
}

void SplitInteger::leeren(){
    zahlen.clear();
}

void SplitInteger::split(string zeichenkette){
    leeren();
    string original = zeichenkette;
    for (int i = 0; i < original.length(); i++)
        zahlen.push_back(stoi(original.substr(i, 1)));
}

void SplitInteger::add(int eingabe){
    zahlen.push_back(eingabe);
}

void SplitInteger::operator=(vector<int> other){
    zahlen.clear();
    for (int i = 0; i < other.size(); i++)
        zahlen.push_back(other[i]);
}

int SplitInteger::max(){
    SplitInteger temp;
    temp = zahlen;
    temp.sortieren();
    return temp[temp.size()-1];
}

int SplitInteger::min(){
    SplitInteger temp;
    temp = zahlen;
    temp.sortieren();
    return temp[0];
}

void SplitInteger::sortieren(){
    sort(zahlen.begin(), zahlen.end());
}

int SplitInteger::operator[](int index){
    return zahlen[index];
}

int SplitInteger::size(){
    return zahlen.size();
}

vector<int> SplitInteger::getZahlen(){
    return zahlen;
}

void SplitInteger::ausgabe(){
    for (int i = 0; i < zahlen.size(); i++)
        cout << zahlen[i] << endl;
}

void SplitInteger::split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length(); i++){
        if (original.substr(i, 1) == trennzeichen){
            zahlen.push_back(stoi(original.substr(anfang, vorschub)));
            anfang = i + 1;
            vorschub = 0;
        }
        else{
            vorschub++;
        }
    }
    zahlen.push_back(stoi(original.substr(anfang, original.length() - anfang)));
}


class easy{
private:
    vector<string> text;
public:
    void add(string eingabe);
    void add(int eingabe);
    void ausgabe();
};

void easy::add(string eingabe){
    text.push_back(eingabe);
}

void easy::add(int eingabe){
    text.push_back(to_string(eingabe));
}

void easy::ausgabe(){
    for (int i = 0; i < text.size(); i++)
        cout << text[i] << endl;
}



int main() {
    SplitInteger cities;
    easy ergebnis;
    int n, min, max;
    string eingabe = "2";
    getline(cin, eingabe);
    n = stoi(eingabe);
    getline(cin, eingabe);
    cities.split(eingabe, " ");
    min = cities[1] - cities[0];
    max = cities[cities.size() - 1] - cities[0];
    eingabe = to_string(min) + " " + to_string(max);
    ergebnis.add(eingabe);
    for (int j = 1; j < cities.size() - 1; j++) {
        if ((cities[j + 1] - cities[j]) > (cities[j] - cities[j - 1]))
            min = (cities[j] - cities[j - 1]);
        else
            min = (cities[j + 1] - cities[j]);

        if ((cities[j] - cities[0]) > (cities[cities.size()-1] - cities[j]))
            max = (cities[j] - cities[0]);
        else
            max = (cities[cities.size()-1] - cities[j]);
        eingabe = to_string(min) + " " + to_string(max);
        ergebnis.add(eingabe);
    }
    min = cities[cities.size()-1] - cities[cities.size()-2];
    max = cities[cities.size() - 1] - cities[0];
    eingabe = to_string(min) + " " + to_string(max);
    ergebnis.add(eingabe);

    ergebnis.ausgabe();

    return 0;
}
