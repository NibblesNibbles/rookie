#include <iostream>

using namespace std;
int main() {
    cout<<"Enter 10 Elements of Set A:\n";
    int A[10];
    for (int i=0;i<10;i++) cin >> A[i];
    cout<<"Enter 10 Elements of Set B:\n";
    int B[10];
    int C[10] ;
    int count = 0;
    for (int i=0;i<10;i++) cin >> B[i];

    for (int i=0;i<10;i++) {
        for (int j = 0; j < 10; j++) {
            if (A[i] == B[j]) {
                C[count] = A[i];
                count++;
            }
        }
    }
    if (count == 0) cout<<"The Intersected Element of Set A and B are not Found.\n";
    else cout <<"The Intersected Elements of Set A and B are:\n";
    for (int i=0;i<count;i++) cout << C[i]<<" ";
    return 0;
}