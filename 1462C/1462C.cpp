#include <iostream>
#include <vector>

using namespace std;

class easy{
    private:
        vector<string> text;
    public:
        void add(string eingabe);
        void add(int eingabe);
        void ausgabe();
};

void easy::add(string eingabe){
    text.push_back(eingabe);
}

void easy::add(int eingabe){
    text.push_back(to_string(eingabe));
}

void easy::ausgabe(){
    for (int i = 0; i < text.size(); i++)
        cout << text[i] << endl;
}

int main(){
    easy ausgabe;
    int t, x;
    cin >> t;
    for (int i = 0; i < t; i++){
        cin >> x;
        switch (x){
            case 1:
                ausgabe.add(1);
                break;
            case 2:
                ausgabe.add(2);
                break;
            case 3:
                ausgabe.add(3);
                break;
            case 4:
                ausgabe.add(4);
                break;
            case 5:
                ausgabe.add(5);
                break;
            case 6:
                ausgabe.add(6);
                break;
            case 7:
                ausgabe.add(7);
                break;
            case 8:
                ausgabe.add(8);
                break;
            case 9:
                ausgabe.add(9);
                break;
            case 10:
                ausgabe.add(19);
                break;
            case 11:
                ausgabe.add(29);
                break;
            case 12:
                ausgabe.add(39);
                break;
            case 13:
                ausgabe.add(49);
                break;
            case 14:
                ausgabe.add(59);
                break;
            case 15:
                ausgabe.add(69);
                break;
            case 16:
                ausgabe.add(79); break;
            case 17:
                ausgabe.add(89); break;
            case 18:
                ausgabe.add(189); break;
            case 19:
                ausgabe.add(289); break;
            case 20:
                ausgabe.add(389); break;
            case 21:
                ausgabe.add(489); break;
            case 22:
                ausgabe.add(589); break;
            case 23:
                ausgabe.add(689); break;
            case 24:
                ausgabe.add(789); break;
            case 25:
                ausgabe.add(1789); break;
            case 26:
                ausgabe.add(2789); break;
            case 27:
                ausgabe.add(3789); break;
            case 28:
                ausgabe.add(4789); break;
            case 29:
                ausgabe.add(5789); break;
            case 30:
                ausgabe.add(6789); break;
            case 31:
                ausgabe.add(16789); break;
            case 32:
                ausgabe.add(26789); break;
            case 33:
                ausgabe.add(36789); break;
            case 34:
                ausgabe.add(46789); break;
            case 35:
                ausgabe.add(56789); break;
            case 36:
                ausgabe.add(156789); break;
            case 37:
                ausgabe.add(256789); break;
            case 38:
                ausgabe.add(356789); break;
            case 39:
                ausgabe.add(456789); break;
            case 40:
                ausgabe.add(1456789); break;
            case 41:
                ausgabe.add(2456789); break;
            case 42:
                ausgabe.add(3456789); break;
            case 43:
                ausgabe.add(13456789); break;
            case 44:
                ausgabe.add(23456789); break;
            case 45:
                ausgabe.add(123456789); break;
        }
        if (x > 45)
            ausgabe.add(-1);
    }
    ausgabe.ausgabe();
    return EXIT_SUCCESS;
}