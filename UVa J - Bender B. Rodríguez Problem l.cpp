#include <iostream>
using namespace std;

int main() {
    int L;
    char c1,c2;
    char c3,c4;
    while (true) {
        c3 = '+';
        c4 = 'x';
        cin >> L;
        if (L == 0) break;
        for (int i=0;i<L-1;i++){
            cin >> c1 >> c2;
            if (c1 == 'N') continue;
            if (c4 == 'x'){
                c4 = c2;
                if (c1 == c3) c3 ='+';
                else c3 = '-';
            }else if (c4 == c2)  {
                if (c1 == c3 ) c3 = '-';
                else c3 = '+';
                c4 = 'x';
            }
        }
        cout << c3 << c4<<endl;
    }
    return 0;
}