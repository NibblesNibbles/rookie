#include <iostream>
#include <string>
using namespace std;

int main() {
    string s,t;
    while (cin>>s){
        bool r = true;
        cin >> t;
        int n=-1;
        for (int i=0;s[i];i++){
             n = t.find(s[i],n+1);
             if (n==-1){
                 r = false;
                 break;
             }
        }
        if (r) cout << "Yes"<<endl;
        else cout <<"No"<<endl;
    }
    return 0;
}