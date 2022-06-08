#include <iostream>

using namespace std;

int solve(){
    int n, anzahl = 0;
    cin >> n;
    if (n < 2020){
        cout << "NO" << endl;
        return 0;
    }

    while(n % 2020 != 0 && n >= 2020){
        n -= 2021;
    }

    n = n % 2020;

    if (n == 0)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 1;
}

int main(){
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
        solve();

    return EXIT_SUCCESS;
}