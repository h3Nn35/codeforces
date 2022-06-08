#include <iostream>

using namespace std;

int main(){
    int m, n, points, winner = 0;
    cin >> m >> n;
    points = m * n;
    while(points > 0){
        winner++;
        m--;
        n--;
        points = m * n;
    }
    if (winner % 2 == 0)
        cout << "Malvika" << endl;
    else
        cout << "Akshat" << endl;
    return EXIT_SUCCESS;
}