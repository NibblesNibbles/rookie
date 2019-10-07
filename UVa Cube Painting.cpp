#include <iostream>
#include <string>
using namespace std;


int main() {
    string s;
    while (cin >> s) {
        string a = "0", b = "0", a1, a2, a3, b1, b2;
        a += s.substr(0, 6);
        b += s.substr(6, 6);
        int n1 = a[1] + a[6], n2 = a[2] + a[5], n3 = a[3] + a[4];
        int m1 = b[1] + b[6], m2 = b[2] + b[5], m3 = b[3] + b[4];
        int max1 = max(n1, n2), max2 = max(m1, m2), min1 = min(n1, n2), min2 = min(m1, m2);
        max1 = max(max1, n3);
        max2 = max(max2, m3);
        min1 = min(min1, n3), min2 = min(min2, m3);
        if (max1 == max2 && min1 == min2 && n1 + n2 + n3 == m1 + m2 + m3) {
            if(!(max1=='r'+'g'&&min1=='g'+'b'&&n1+n2+n3==2*('r'+'b'+'g'))) cout << "TRUE\n";
            else {
                a1 = to_string('\0') + a[1] + a[5] + a[4] + a[3] + a[2] + a[6];
                a2 = to_string('\0') + a[6] + a[5] + a[3] + a[4] + a[2] + a[1];
                a3 = to_string('\0') + a[6] + a[2] + a[4] + a[3] + a[5] + a[1];
                b1 = to_string('\0') + b[3] + b[1] + b[2] + b[4] + b[6] + b[5];
                b2 = to_string('\0') + b[2] + b[3] + b[1] + b[5] + b[4] + b[6];
                if (b==a||b==a1||b==a2||b==a3||b1==a||b1==a1||b1==a2||b1==a3||b2==a||b2==a1||b2==a2||b2==a3)
                    cout <<"TRUE\n";
                else cout<<"FALSE\n";
            }
        }else cout<<"FALSE\n";
    }
    return 0;
}