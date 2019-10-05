#include <iostream>

using namespace std;

class my {
public:
    bool b;
    char ch;
};

int main() {
    int r,c;
    int t =1;
    while (true) {
        string a="Across\n",d="Down\n";
        int n = 1;
        cin >> r;
        if (r==0) break;
        cin >> c;
        my s[r][c];
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++){
                s[i][j].b=false;
                cin>>s[i][j].ch;
                if (s[i][j].ch=='*') s[i][j].b=true;
            }
        }
        for (int i=0;i<r;i++){
            for (int j=0;j<c;j++) {
                if ((i == 0 || j == 0 || s[i - 1][j].b || s[i][j - 1].b) && !s[i][j].b) {
                    if (j == 0 || s[i][j - 1].b) {
                        a += (n>9?" ":"  ") + to_string(n)+'.';
                        for (int tem = j; tem < c && !s[i][tem].b; tem++)
                            a += s[i][tem].ch;
                        a +='\n';
                    }
                    if (i == 0 || s[i-1][j].b) {
                        d += (n>9?" ":"  ") + to_string(n)+'.';
                        for (int tem = i; tem < r && !s[tem][j].b; tem++)
                            d += s[tem][j].ch;
                        d +='\n';
                    }
                    n++;
                }
            }
        }
        if (t !=1) cout <<'\n';
        cout << "puzzle #"<<t<<":\n"<<a<<d;
        t++;
    }
    return 0;
}

