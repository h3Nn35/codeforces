#include <iostream>

using namespace std;

int main(){
    int n = 4, i = 0;
    string text = "1100";
    cin >> n;
    cin >> text;
    while(i < n - 1){
        if ((text[i] == '0' && text[i + 1] == '1') || (text[i] == '1' && text[i + 1] == '0')){
            text.replace(i, 2, "");
            if (i != 0)
                i--;
            n = text.length();
        }
        else
            i++;
    }

    cout << text.length();

    return EXIT_SUCCESS;
}