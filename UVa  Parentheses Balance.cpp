#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    while (getline(cin, s)) {
        string r;
        for (int i = 0; s[i]; i++) {
            if (s[i] == ']') continue;
            if (s[i] == '[') {
                string sub;
                i++;
                while (s[i] && s[i] != ']') {
                    if (s[i] == '[') {
                        i--;
                        break;
                    } else {
                        sub += s[i];
                        i++;
                    }
                }
                r = sub + r;
            } else r += s[i];
        }
        cout << r << endl;
    }
    return 0;
}