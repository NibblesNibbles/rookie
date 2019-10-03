#include <iostream>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    string s,p,q;
    for (int i=0;i<N;i++){
        cin >> s;
        int n = s.size();
        for (int j=1;j<=n;j++){
            if (n%j==0){
                q = p = s.substr(0,j);
                for (int k=1;k< n/j;k++)
                    q += p;
                if (q==s) {
                    if (i!=0) cout << "\n";
                    cout << j << endl;
                    break;
                }
            }
        }
    }
    return 0;
}