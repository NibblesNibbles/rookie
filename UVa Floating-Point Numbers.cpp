#include <iostream>
#include <cmath>

using namespace std;

int main() {
    double d = pow(10,-5);
    double c,c1,c2;
    string s,s2,s1;
    double n[10][30];
   for (int i=0;i<10;i++){
       for (int j=0;j<30;j++)
           n[i][j] = pow(2,j+1)+log2(1-pow(2,(i+1)*-1))-1;
   }

   while(cin>>s) {
       if (s =="0e0") break;
       bool flag = true;
       s1 =s.substr(0,17);
       s2 =s.substr(18,s.size()-18);
       c1 = stod(s1);
       c2 = stod(s2);
       c = log2(c1)+c2*log2(10);
       for (int i = 0; i < 10 && flag; i++) {
           for (int j = 0; j < 30 && flag; j++) {
               if (abs(c - n[i][j]) < d) {
                   cout << i << " " << j + 1 << endl;
                   flag = false;
               }
           }
       }
   }
    return 0;
}