#include <iostream>

using namespace std;

int main(){
    string eingabe = "", ausgabe = "";
    int i = 0;

    getline(cin, eingabe);

    do{
        if (eingabe.substr(i, 1) == "."){
            ausgabe = ausgabe + "0";
            i++;
        }
        else if (eingabe.substr(i, 1) == "-" and eingabe.substr(i + 1, 1) == ".")
        {
            ausgabe = ausgabe + "1";
            i += 2;
        }
        else if (eingabe.substr(i, 1) == "-" and eingabe.substr(i + 1, 1) == "-")
        {
            ausgabe = ausgabe + "2";
            i += 2;
        }
    } while (i < eingabe.length());

    cout << ausgabe << endl;
}