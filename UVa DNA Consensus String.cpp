#include <iostream>
using namespace std;

int main() {
    int T,m,n;
    int a,t,c,g,l,s;
    cin >> T;
    while (T--){
        s = 0;
        cin >>m>>n;
        char u[m][n];
        char r[n];
        for (int i=0;i<m;i++)
            for (int j=0;j<n;j++)
                cin >> u[i][j];

        for (int j=0;j<n;j++){
             a=0;t=0; c=0;g=0;
            for (int i=0;i<m;i++){
                switch (u[i][j]) {
                    case 'A': a++; break;
                    case 'C': c++; break;
                    case 'G': g++; break;
                    case 'T': t++; break;
                }
            }
            l = max(a,c);
            l = max(l,g);
            l = max(l,t);
            if (l==a) r[j]='A';
            else if (l==c) r[j]='C';
            else if (l==g) r[j]='G';
            else r[j]='T';
            cout << r[j];
            s += a+c+g+t-l;
        }
        cout << '\n'<<s<<'\n';
    }
    return 0;
}