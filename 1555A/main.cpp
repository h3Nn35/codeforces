#include <iostream>
#include <vector>

using namespace std;

class easy{
private:
    vector<string> text;
public:
    void add(const string & eingabe);
    void add(long long eingabe);
    void ausgabe();
};

void easy::add(const string & eingabe){
    text.push_back(eingabe);
}

void easy::add(long long eingabe){
    text.push_back(to_string(eingabe));
}

void easy::ausgabe(){
    for (auto & i : text)
        cout << i << endl;
}

int main() {
    easy ergebnis;
    int t;
    long long n;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> n;
        if (n < 6)
            n = 6;
        else if (n % 2 != 0)
            n++;
        ergebnis.add(n/2*5);
    }
    ergebnis.ausgabe();
    return 0;
}
