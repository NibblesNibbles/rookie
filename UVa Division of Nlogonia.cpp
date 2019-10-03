#include <iostream>
#include <string>
using namespace std;

int main(){
    int K,cx,cy,qx,qy;
    string output;
    while (true) {
        cin >> K ;
        if (K == 0)
            break;
        cin >> cx >> cy;
        for (int i = 0; i < K; i++) {
            cin >> qx >> qy;
            if (qx > cx && qy > cy) {
                output += "NE\n";
            } else if (qx > cx && qy < cy) {
                output += "SE\n";
            } else if (qx < cx && qy < cy) {
                output += "SO\n";
            } else if (qx < cx && qy > cy) {
                output += "NO\n";
            } else output += "divisa\n";
        }
    }
    cout << output;
    return 0;
}