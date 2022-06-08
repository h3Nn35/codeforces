#include <iostream>

using namespace std;

void solve(){
    int n = 15116544, anzahl2 = 0, anzahl3 = 0;
    cin >> n;
    while(n % 2 == 0){
        n /= 2;
        anzahl2++;
    }
    while(n % 3 == 0){
        n /= 3;
        anzahl3++;
    }
    if (n != 1 || anzahl2 > anzahl3)
        cout << -1 << endl;
    else
        cout << anzahl3 - anzahl2 + anzahl3 << endl;
}

int main(){
    int t = 1;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return EXIT_SUCCESS;
}