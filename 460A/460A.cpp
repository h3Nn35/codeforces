#include <iostream>

using namespace std;

int main(){
    int m, n, antwort, socken;
    cin >> n >> m;
    antwort = n;
    socken = n / m;
    while(socken > 0){
        socken--;
        antwort++;
        if (antwort % m == 0)
            socken++;
    }

    cout << antwort << endl;

    return EXIT_SUCCESS;
}