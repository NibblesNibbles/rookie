#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    string r;
    int T,n1,n2,n3,m,l,s;
    cin >> T;
    for (int i=1;i<=T;i++){
        cin >>n1>>n2>>n3;
        m = max(n1,n2);
        m = max(m,n3);
        l = min(n1,n2);
        l = min(l,n3);
        if (n1!=l && n1!= m){
            s = n1;
        }else if (n2 !=l && n2!=m) {
            s = n2;
        }else s = n3;
        r += "Case "+ to_string(i) + ": "+ to_string(s)+"\n";
    }
    cout << r;
    return 0;
}