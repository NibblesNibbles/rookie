#include <iostream>
using namespace std;

int main() {
    int T,N,h,h0,hj,lj;
    cin >> T;
    for (int i=0;i<T;i++){
        cin >> N >> h0;
        hj = 0;
        lj = 0;
        for (int j=1;j<N;j++){
            cin >> h;
            if (h-h0 < 0) lj++;
            else if (h-h0 > 0) hj++;
            h0 = h;
        }
        cout << "Case "<<i+1<<": "<<hj <<" "<<lj<<endl;
    }
    return 0;
}