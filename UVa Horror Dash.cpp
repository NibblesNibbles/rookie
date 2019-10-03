#include <iostream>
using namespace std;

int main() {
    int T,N,s,r;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N ;
        r = 0;
        for (int j=0;j<N;j++){
            cin >> s;
            r = max(r, s);
        }
        cout << "Case "<<i+1<<": "<<r<<endl;
    }
    return 0;
}