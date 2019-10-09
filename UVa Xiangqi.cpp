#include <iostream>

using namespace std;


int main() {
    int N, x, y;
    while (cin >> N) {
        if (N == 0) break;
        cin >> x >> y;
        char t[N];
        int X[N];
        int Y[N];
        for (int i = 0; i < N; i++) {
            cin >> t[i] >> X[i] >> Y[i];
        }
        bool b = true;
        for (int i = 1; i < 4 && b; i++) {
            for (int j = 4; j < 7 && b; j++) {
                if (abs(x - i) + abs(y - j) == 1) {
                    bool B = true;
                    for (int k = 0; k < N && B; k++) {
                        if (X[k] != i || Y[k] != j) {
                            switch (t[k]) {
                                case 'G':
                                    if (Y[k] == j) {
                                        bool c = true;
                                        for (int l = 0; l < N && c; l++)
                                            if (l != k) c = (Y[l] != j || X[l] <= min(i, X[k]) || X[l] >= max(i, X[k]));
                                        B = !c;
                                    }
                                    break;
                                case 'R':
                                    if (Y[k] == j) {
                                        bool c = true;
                                        for (int l = 0; l < N && c; l++)
                                            if (l != k) c = (Y[l] != j || X[l] <= min(i, X[k]) || X[l] >= max(i, X[k]));
                                        B = !c;
                                    }
                                    if (X[k] == i) {
                                        bool c = true;
                                        for (int l = 0; l < N && c; l++)
                                            if (l != k) c = (X[l] != i || Y[l] <= min(j, Y[k]) || Y[l] >= max(j, Y[k]));
                                        B = !c;
                                    }
                                    break;
                                case 'C':
                                    if (Y[k] == j) {
                                        int c = 0;
                                        for (int l = 0; l < N && c < 2; l++)
                                            if (l != k)
                                                c += !(Y[l] != j || X[l] <= min(i, X[k]) || X[l] >= max(i, X[k]));
                                        if (c == 1) B = false;
                                    }
                                    if (X[k] == i) {
                                        int c = 0;
                                        for (int l = 0; l < N && c < 2; l++)
                                            if (l != k)
                                                c += !(X[l] != i || Y[l] <= min(j, Y[k]) || Y[l] >= max(j, Y[k]));
                                        if (c == 1) B = false;
                                    }
                                    break;
                                case 'H':
                                    if (abs(X[k] - i) == 2 && abs(Y[k] - j) == 1) {
                                        bool c = true;
                                        for (int l = 0; l < N && c; l++)
                                            if (l != k) c = !(Y[l] == Y[k] && X[l] == (X[k] + i) / 2);
                                        B = !c;
                                    }
                                    if (abs(X[k] - i) == 1 && abs(Y[k] - j) == 2) {
                                        bool c = true;
                                        for (int l = 0; l < N && c; l++)
                                            if (l != k) c = !(X[l] == X[k] && Y[l] == (Y[k] + j) / 2);
                                        B = !c;
                                    }
                                    break;
                            }
                        }
                    }
                    b = !B;
                }
            }
        }
        cout << (b ? "YES\n" : "NO\n");
    }
    return 0;
}