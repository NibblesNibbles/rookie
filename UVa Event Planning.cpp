#include <iostream>

using namespace std;

int main() {
    int N, B, H, W, p;
    while (cin >> N) {
        cin >> B >> H >> W;
        int bmin = B + 1;
        int b, n;
        for (int i = 0; i < H; i++) {
            cin >> p;
            for (int j = 0; j < W; j++) {
                cin >> n;
                if (n >= N) {
                    b = p * N;
                    bmin = min(bmin, b);
                }
            }
        }
        if (bmin <= B) cout << bmin << endl;
        else cout << "stay home" << endl;
    }
    return 0;
}