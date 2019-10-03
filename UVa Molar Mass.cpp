#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main() {
    int T;
    double result;
    char e;
    cin >> T;
    double c = 12.01, h = 1.008, o = 16.00, n = 14.01;
    string s;
    string sn;
    for (int i=0;i<T;i++){
        int b=0,num;
        result = 0;
        cin >> s;
        s += "E";
        e = s[0];
        for (int j=1;s[j];j++){
            if (s[j]-'0'>10 ) {
                if (j>b+1){
                    sn = s.substr(b+1, j -b-1);
                    num = atoi(sn.c_str());
                }else num = 1;
                switch (e){
                    case 'C': result += c*num; break;
                    case 'H': result += h*num; break;
                    case 'N': result += n*num; break;
                    case 'O': result += o*num; break;
                }
                b = j;
                e = s[j];
            }
        }
        cout << setprecision(3)<<fixed<<result<<endl;
    }
    return 0;
}