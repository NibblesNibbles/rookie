#include <iostream>
using namespace std;

int main() {
    cout <<"Enter the current year:\n"
           "Enter the current month:\n";
    int  cy,cm,ca,bm,fy,fm;
    cin >>cy>>cm;
    if (cm>12 || cm<1){
        cout << "Invalid Month Input!";
    }else {
        cout << "Enter your current age in years:\n";
        cin >> ca;
        if (ca < 0) cout << "The value for age cannot be a negative integer!";
        else if (ca > 200) cout << "Sorry, people may be dead by this age!";
        else {
            cout << "Enter the month in which you were born:\n";

            cin >> bm;
            if (bm > 12 || bm < 1) cout << "Invalid Month Input!";
            else {
                cout << "Enter the year for which you wish to know your age:\n"
                        "Enter the month in the year for which you wish to know your age:\n";
                cin >> fy >> fm;
                if (fm > 12 || fm < 1) cout << "Invalid Month Input!";
                else {
                    int fa = ca + fy - cy;
                    int fam = fm - bm;
                    if (fam < 0) {
                        fam += 12;
                        fa -= 1;
                    }
                    if (fa < 0) cout << "You were not born!";
                    else {
                        cout << "Your age in " << fy << "/" << fm << ":\n" << fa << " year";
                        if (fa != 0 && fa != 1) cout << "s";
                        cout << " and " << fam << " month";
                        if (fam != 0 && fam != 1) cout << "s";
                        cout << "\n";
                        if (fa % 2 == 1 && fam % 2 == 1) cout << "Both of " << fa << " and " << fam << " are odd!";
                        else if (fa % 2 == 1 && fam % 2 == 0) cout << fa << " is odd!";
                        else if (fa % 2 == 0 && fam % 2 == 1) cout << fam << " is odd!";
                        else cout << "Both of " << fa << " and " << fam << " are not odd!";
                    }
                }
            }
        }
    }
    return 0;
}