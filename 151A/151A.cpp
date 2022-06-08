#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> split(string zeichenkette, string trennzeichen){
    string original = zeichenkette;
    vector<int> text;
    int anfang = 0, vorschub = 0;
    for (int i = 0; i < original.length() - 1; i++){
        if (original.substr(i, 1) == trennzeichen){
            text.push_back(stoi(original.substr(anfang, vorschub)));
            anfang = i + 1;
            vorschub = 0;
        }
        else{
            vorschub++;
        }
    }
    text.push_back(stoi(original.substr(anfang, original.length() - anfang)));
    return text;
}


int main(){
    int n, k, l, c, d, p, nl, np;
    int drinks, slices, salt, result;
    vector<int> min, gesplittet;
    string eingabe;

    getline(cin, eingabe);

    gesplittet = split(eingabe, " ");
    
    n = gesplittet[0];
    k = gesplittet[1];
    l = gesplittet[2];
    c = gesplittet[3];
    d = gesplittet[4];
    p = gesplittet[5];
    nl = gesplittet[6];
    np = gesplittet[7];
    
    drinks = k * l / nl;
    slices = c * d;
    salt = p / np;
    
    min.push_back(k * l / nl);
    min.push_back(c * d);
    min.push_back(p / np);
    sort(min.begin(), min.end());    
    result = min[0] / n;
    
    cout << result << endl;

    return EXIT_SUCCESS;
}