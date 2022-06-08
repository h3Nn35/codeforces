#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class SplitInteger{
    private:
        vector<int> zahlen;
    public:
        void split(string zeichenkette, string trennzeichen);
        vector<int> getZahlen();
        void ausgabe();
        void sortieren();
        void operator=(vector<int> other);
        int size();
        int operator[](int index);
        int max();
        int min();
};

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
    for (int i = 0; i < zahlen.size(); i++){
        if (i < zahlen.size()-1)
            cout << zahlen[i] << " ";
        else
            cout << zahlen[i];
    }
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

int main(){
    SplitInteger eingabe1, puzzle;
    int n, m, min, akutell;
    string eingabe;
    getline(cin, eingabe);
    eingabe1.split(eingabe, " ");
    getline(cin, eingabe);
    puzzle.split(eingabe, " ");
    puzzle.sortieren();
    min = puzzle.max();

    n = eingabe1[0];
    m = eingabe1[1];

    for (int i = 0; i <= puzzle.size() - n; i++){
        akutell = puzzle[i+n-1] - puzzle[i];
        if (akutell < min)
            min = akutell;
    }

    cout << min;

    return EXIT_SUCCESS;
}