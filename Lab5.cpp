#include <iostream>
#include <cmath>
using namespace std;

int main(){
    int a,b,count=0;
    cout <<"Please input the maximal length allowed for the edge: \n";
    cout <<"Please input the minimal length allowed for the edge: \n";
    cin >>a>>b;
    if (b>0&&a>b) {
    for (int r=2;r<a;r+=2){
        int p=r*r/2;
        for (int i=1;i<=sqrt(p);i++){
            if (p%i==0 && r+i>=b && r+(p/i)+i<=a) count++;
        }
    }
    cout <<"The number of all Pythagorean triplets between "<<b<< " and "<<a  <<" is "<<count<<"."<<endl;
    }else cout <<"Invalid inputs!\n";
    return 0;
}