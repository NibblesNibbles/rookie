#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, l;
    int x = 1;
    while (cin >> n >> l) {
        if (x != 1) cout << "\n" << "**********************************" << "\n\n";
        bool H[n][n - 1], V[n][n - 1];
        int r, c, s[n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n - 1; j++)
                V[i][j] = H[i][j] = false;
            s[i] = 0;
        }
        char t;
        for (int i = 0; i < l; i++) {
            cin >> t >> r >> c;
            if (t == 'H') H[r - 1][c - 1] = true;
            else V[r - 1][c - 1] = true;
        }

        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - 1; j++) {
                bool flag = true;
                for (int k = 0; k < n - max(i, j)-1 && flag; k++) {
                    if (H[i][j+k] && V[j][i+k]) {
                        bool b = true;
                        for (int m = j; m < j + k + 1 && b; m++)
                            b = b && H[i + k + 1][m];
                        for (int m = i; m < i + k + 1 && b; m++)
                            b = b && V[j + k + 1][m];
                        if (b) {
                            s[k]++;
                        }
                    } else flag = false;
                }
            }
        }
        cout << "Problem #" << x << "\n\n";
        string p = "";
        for (int i = 0; i < n; i++) {
            if (s[i] != 0) p += to_string(s[i]) + " square (s) of size " + to_string(i + 1) + "\n";
        }
        if (p == "") p += "No completed squares can be found.\n";
        cout << p;
        x++;
    }
    return 0;
}

