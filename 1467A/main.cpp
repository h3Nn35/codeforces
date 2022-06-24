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

using namespace std;

int main() {
    easy ausgabe;
    int t, n, j;
    string ergebnis = "";
    cin >> t;
    for (int i = 0; i < t; i++){
        ergebnis = "";
        cin >> n;
        j = 9;
        while(n--){
            ergebnis = ergebnis + to_string(j);
            if (j == 0)
                j = 9;
            else
                j--;
        }
        ausgabe.add(ergebnis);
    }
    ausgabe.ausgabe();
    return 0;
}
