#include <iostream>
#include <cstring>

using namespace std;

int main(){
    string t;

    getline(cin, t);

    for (int i = 0; i < stoi(t); i++){
        string input;
        getline(cin, input);

        for (auto & c: input) c = toupper(c);

        // input = toupper(input);

        if (input == "YES")
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}