#include <iostream>

using namespace std;

int main() {
   int T;
   string s;
   cin >> T;

   for (int i=0;i<T;i++){
     int n=0,r=0;
     cin >>s;
     for (int j=0;s[j];j++){
         if (s[j]=='O'){
             r += 1+n;
             n++;
         }else n = 0;
     }
     cout << r<<endl;
   }
    return 0;
}