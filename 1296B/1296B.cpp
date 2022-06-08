#include <iostream>
#include <vector>
#include <cmath>
#include <stdio.h>

using namespace std;

class easy{
    private:
        vector<string> text;
    public:
        void add(string eingabe);
        void ausgabe();
};

void easy::add(string eingabe){
    text.push_back(eingabe);
}

void easy::ausgabe(){
    for (int i = 0; i < text.size(); i++)
        cout << text[i] << endl;
}

int main(){
    easy ausgabe;
    int t;
	cin >> t;
	while (t--) {
		int s;
		cin >> s;
		int ans = 0;
		int pw = 1000 * 1000 * 1000;
		while (s > 0) {
			while (s < pw) pw /= 10;
			ans += pw;
			s -= pw - pw / 10;
		}
		ausgabe.ausgabe();
	}

    ausgabe.ausgabe();
    return EXIT_SUCCESS;
}