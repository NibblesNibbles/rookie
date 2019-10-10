#include <iostream>
#include <cmath>
#include <bitset>
using namespace std;

void covert(bitset<32> T,int t[4]){
    long long x = T.to_ulong() ;
    for (int i=0;i<4;i++){
        t[i] = x%256;
        x = x/256;
    }
}

int main() {
    int n;
    while (cin>>n){
    bitset<32> b[n],mask,address;
    int B[4],m[4],a[4];
    char t;
    for (int i=0;i<n;i++){
        unsigned sum=0;
        for (int j=0;j<4;j++){
            if (j>0) cin >>t;
            cin >>B[j];
            sum += B[j]*pow(2,8*(3-j));
        }
        b[i]=(sum);
        if (i==0) mask= ~mask;
        else mask &= ~(b[0]^b[i]);
    }
    for (int i=31;i>0;i--){
        if (!mask[i]){
             for (int j=1;j<i+1;j++) mask[i-j]=0;
             break;
        }
    }

    address = b[0]&mask;
    covert(mask,m);
    covert(address,a);
    cout<<a[3]<<'.'<<a[2]<<'.'<<a[1]<<'.'<<a[0]<<endl;
    cout<<m[3]<<'.'<<m[2]<<'.'<<m[1]<<'.'<<m[0]<<endl;
    }
    return 0;
}