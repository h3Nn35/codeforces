#include <iostream>
#include <vector>

using namespace std;

int main(){
    vector<long long> tests;
    long long n, eingabe, aktuell;

    n = 1;
    cin >> n;

    for (int i = 0; i < n; i++){
        eingabe = 6;
        cin >> eingabe;
        tests.push_back(eingabe);
    }

    for (int i = 0; i < tests.size(); i++){
        aktuell = tests[i];
        if (aktuell & (aktuell - 1))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }


    return EXIT_SUCCESS;
}