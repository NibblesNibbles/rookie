#include <iostream>

using namespace std;

int main() {
    int t = 1;
    while (true) {
        int n, p;
        cin >> n >> p;
        if (n == 0 && p == 0)
            break;
        char req[80];
        char name[80];
        char result[80];
        double d;
        double d0 ;
        int r, r0 = -1;
        for (int i = 0; i < n + 1; i++) {
            cin.getline(req, 81);
        }
        for (int i = 0; i < p; i++) {
            cin.getline(name, 81);
            cin >> d >> r;
            if ((r==r0 && d<d0) || r>r0) {
                r0 = r;
                d0 = d;
                for (int j = 0; j < 80; j++)
                    result[j] = name[j];
            }
            for (int k = 0; k < r + 1; k++) {
                cin.getline(req, 81);
            }
        }
        if (t != 1)
            cout << "\n";
        cout << "RFP #" << t << "\n" << result << endl;
        t++;
    }
    return 0;
}