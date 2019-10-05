#include <iostream>
using namespace std;
int main() {
    int a,b;
    while (cin >> a >>b) {
        string s;
        int c[b];
        bool flag = true;
        cout << a <<'/'<<b<<" = ";
        for (int i = 0; flag; i++) {
            c[i] = a % b;
            s += to_string(a/b);
            if (i==0) s += '.';
            a = 10 * c[i];
            for (int j = 0; j < i && flag; j++) {
                if (c[j] == c[i]) {
                    flag = false;
                    int n=s.size();
                    s += ' ';
                    for (int k=n-1;k>n-1+j-i;k--) s[k+1]=s[k];
                    s[n+j-i] ='(';
                    if (s.size()-s.find('.')>52){
                        s = s.substr(0,s.find('.')+52);
                        s +="...";
                    }
                    s +=')';
                    s +="\n   " +to_string(i-j);
                }
            }
        }
        cout <<s<< " = number of digits in repeating cycle\n\n";
    }
    return 0;
}