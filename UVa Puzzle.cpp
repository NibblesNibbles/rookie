#include <iostream>
#include <string>
using namespace std;

int main() {
    bool flag = true;
    bool legal;
    int t = 1;
    string S, s, C,c;
    while (true) {
        legal = true;
        S = "";
        for (int i = 0; i < 5; i++) {
            getline(cin, s);
            if (s == "Z") {
                flag = false;
                break;
            }
            if (s.size()==4) s += " ";
            S += s;
        }
        if (!flag) break;

        c ="";
        C ="";
        while (c.find('0')==-1) {
            getline(cin, c);
            C += c;
        }

        for (int i = 0; i < C.size(); i++) {
            int n = S.find(' ');
            switch (C[i]) {
                case 'A':
                    if (n >= 5) {
                        S[n] = S[n - 5];
                        S[n - 5] = ' ';
                    } else legal = false;
                    break;
                case 'B':
                    if (n <= 19) {
                        S[n] = S[n + 5];
                        S[n + 5] = ' ';
                    } else legal = false;
                    break;
                case 'R':
                    if (n % 5 != 4) {
                        S[n] = S[n + 1];
                        S[n + 1] = ' ';
                    } else legal = false;
                    break;
                case 'L':
                    if (n % 5 != 0) {
                        S[n] = S[n - 1];
                        S[n - 1] = ' ';
                    } else legal = false;
                    break;
            }
            if (!legal) break;
        }
        if (t != 1) cout << '\n';
        cout << "Puzzle #" << t << ":" << endl;
        if (legal)
            for (int i = 0; i < 25; i ++){
                cout << S[i];
                if (i%5 != 4) cout <<' ';
                else cout << '\n';
            }
        else cout << "This puzzle has no final configuration."<<endl;
        t++;
    }
    return 0;
}