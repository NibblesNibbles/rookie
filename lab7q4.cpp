#include <iostream>
#include <cstring>

using namespace std;
int main() {
    cout <<"Enter the First Name:\n";
    string s;
    cin >>s;
    int n = s.size();
    bool p = true;
    for (int i=0;i<n/2&&p;i++){
        if (s[i] !=s[n-i-1]) p =false;
    }
    if (p) cout <<s<<" is palindrome";
    else cout <<s<<" is not palindrome";
    return 0;
}