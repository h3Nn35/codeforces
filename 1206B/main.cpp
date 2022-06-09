#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitInteger{
private:
    vector<long long> zahlen;
public:
    void split(string zeichenkette);
    void split(string zeichenkette, string trennzeichen);
    auto begin();
    auto end();
    void splitby(string zeichenkette, char trennzeichen);
    void leeren();
    vector<long long> getZahlen();
    void add(long long eingabe);
    void add(string eingabe);
    void ausgabe();
    void sortieren();
    void operator=(vector<long long> other);
    int size();
    long long operator[](int index);
    string operator=(string eingabe);
    long long operator=(long long eingabe);
    int getIndexOf(long long zahl);
    int getPositionBiggest();
    long long max();
    long long min();
    void einzelnesEntfernen(int index);
};



long long SplitInteger::operator=(long long eingabe){
    split(to_string(eingabe));
    return eingabe;
}

string SplitInteger::operator=(string eingabe){
    split(eingabe);
    return eingabe;
}

int SplitInteger::getIndexOf(long long zahl){
    for (int i = 0; i < size(); i++)
        if (zahlen[i] == zahl)
            return i;
    return -1;
}

int SplitInteger::getPositionBiggest(){
    return getIndexOf(max());
}

void SplitInteger::add(string eingabe){
    if (!eingabe.empty())
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

void SplitInteger::add(long long eingabe){
    zahlen.push_back(eingabe);
}

void SplitInteger::operator=(vector<long long> other){
    zahlen.clear();
    for (int i = 0; i < other.size(); i++)
        zahlen.push_back(other[i]);
}

long long SplitInteger::max(){
    SplitInteger temp;
    temp = zahlen;
    temp.sortieren();
    return temp[temp.size()-1];
}

long long SplitInteger::min(){
    SplitInteger temp;
    temp = zahlen;
    temp.sortieren();
    return temp[0];
}

void SplitInteger::sortieren(){
    sort(zahlen.begin(), zahlen.end());
}

long long SplitInteger::operator[](int index){
    return zahlen[index];
}

int SplitInteger::size(){
    return zahlen.size();
}

vector<long long> SplitInteger::getZahlen(){
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

auto SplitInteger::begin() {
    return zahlen.begin();
}

auto SplitInteger::end() {
    return zahlen.end();
}

int main() {
    SplitInteger test;
    int n, negativ = 0, nullen = 0;
    long long ergebnis = 0;
    string eingabe;
    getline(cin, eingabe);
    n = stoi(eingabe);
    getline(cin, eingabe);
    test.split(eingabe, " ");
    for (auto & j : test){
        if (j > 0)
            ergebnis += j - 1;
        else if (j < 0){
            negativ++;
            ergebnis += abs(j) - 1;
        }
        else {
            nullen++;
            ergebnis++;
        }
    }
    if (negativ % 2 != 0)
        if (nullen == 0)
            ergebnis += 2;
    cout << ergebnis;
    return EXIT_SUCCESS;
}
