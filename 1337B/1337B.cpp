#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int main(){
    vector<string> ausgabe;
    int t;
    cin >> t;
    while(t--){
        int x, n, m;
        cin >> x >> n >> m;

        for (int i = 0; i < n; i++){
            if (floor(x / 2) + 10 < x)
                x = floor(x / 2) + 10;
            else
                break;
        }
        for (int i = 0; i < m; i++){
            x -= 10;
        }

        if (x <= 0)
            ausgabe.push_back("YES");
        else
            ausgabe.push_back("NO");
    }

    for (int i = 0; i < ausgabe.size(); i++)
        cout << ausgabe[i] << endl;

    return EXIT_SUCCESS;
}