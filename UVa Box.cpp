#include <iostream>

using namespace std;

int main() {
   int w[6],h[6],tem;
   while (cin>>w[0]){
       int s[6];
       int A = 0,B=0;
       for (int i=0;i<6;i++) {
           if (i!=0) cin>>w[i];
           cin >>h[i];
           if (w[i]<h[i]) {
               tem = w[i];
               w[i] = h[i];
               h[i] = tem;
           }
       }

       for (int i=0;i<6;i++) {
               for (int j = i + 1; j < 6; j++) {
                   if (w[i] != 0){
                   if (w[i] == w[j] && h[i] == h[j]) {
                       s[A]= w[i];
                       s[A+1] = h[i];
                       w[i] = w[j] = 0;
                       A += 2;
                   }
               }
           }
       }
       if (A==6){
           for (int i=0;i<6;i++) {
               for (int j = i + 1; j < 6; j++) {
                       if (s[i] == s[j] && !(i % 2 == 0 && j == i + 1)) B++;
               }
           }
           if (B==3||B==6||B==12) cout << "POSSIBLE"<<endl;
           else cout <<"IMPOSSIBLE"<<endl;
       }else cout <<"IMPOSSIBLE"<<endl;
   }
    return 0;
}