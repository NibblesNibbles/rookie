#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int N1 , N2 ;
    int n11, n12, n21, n22;
    char name2[26];
    char name1[26];

    while (gets(name1)&&gets(name2)) {
        N1 =0;
        N2 =0;
        for (int i = 0; name1[i]; i++) {
            n11 = name1[i] - 'a' + 1;
            n12 = name1[i] - 'A' + 1;
            if (n11 > 0 && n11 < 27) N1 += n11;
            else if (n12 > 0 && n12 < 27) N1 += n12;
        }

        for (int i = 0; name2[i]; i++) {
            n21 = name2[i] - 'a' + 1;
            n22 = name2[i] - 'A' + 1;
            if (n21 > 0 && n21 < 27) N2 += n21;
            else if (n22 > 0 && n22 < 27) N2 += n22;
        }

        while (N1 >= 10) {
            N1 = N1 / 100 + (N1 % 100) / 10 + N1 % 10;
        }
        while (N2 >= 10) {
            N2 = N2 / 100 + (N2 % 100) / 10 + N2 % 10;
        }
        double r;
        r = min(double(N1) / N2, double(N2) / N1);
        r = 100 * r;
        cout << setprecision(2) << fixed << r << " %" << endl;
    }
    return 0;
}