#include <iostream>
#include <string>
using namespace std;

string out ;
void relation(int n1,int n2){
    if (n1<n2){
        out += "<\n";
    }else if (n1>n2){
        out += ">\n";
    }else out += "=\n";
}

int main() {
    int n , a , b;
    cin >> n ;
    for (int i = 0; i < n ; i ++){
        cin >> a >> b;
        relation(a,b);
    }
    cout << out ;
    return 0;
}