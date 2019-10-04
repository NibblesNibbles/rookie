#include <iostream>
using namespace std;

int main() {
    cout <<"Enter the equation :\n";
    int a,b;
    char o;
    if (cin>>a>>o>>b){
     switch(o){
         case '+': cout <<a<<'+'<<b<<"="<<a+b; break;
         case '-': cout <<a<<'-'<<b<<"="<<a-b; break;
         case '*': cout <<a<<'*'<<b<<"="<<a*b; break;
         case '/': cout <<a<<'/'<<b<<"="<<a/(double)b; break;
         case '%': cout <<a<<'%'<<b<<"="<<a%b; break;
         case '>': cout <<a<<'>'<<b<<'='<< (a>b?'T':'F'); break;
         case '<': cout <<a<<'<'<<b<<'='<< (a<b?'T':'F'); break;
         case '=': cout <<'('<< a <<"=="<<b<<')'<<'='<<(a==b?'T':'F');break;
         default: cout << "Invalid operation.";
     }
    }else cout <<"Invalid input.";
    return 0;
}