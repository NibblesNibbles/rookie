#include <iostream>
using namespace std;

int main() {
    double  downPay,loan,carValue,moneyOwned,monthPay;
    int month,specific;

    while (true){
        cin >> month >>downPay>>loan>>specific;
        if (month<0) break;
        monthPay = loan/month;

        int  monthChange[specific];
        double depreciateRate[specific];
        for (int i=0;i<specific;i++) {
            cin >> monthChange[i] >> depreciateRate[i];
        }

        carValue = (downPay + loan)*(1-depreciateRate[0]);
        moneyOwned = loan;
        if (moneyOwned<carValue){
            cout << "0" << " months"<<endl;
        }
        else {

            int j = 1;
            for (int i = 1; i <= month; i++) {
                if (i == monthChange[j]) j++;
                carValue *= (1 - depreciateRate[j - 1]);
                moneyOwned -= monthPay;
                if (moneyOwned < carValue) {
                    if (i != 1) {
                        cout << i << " months" << endl;
                    } else cout << 1 << " month" << endl;
                    break;
                }
            }
        }
    }
    return 0;
}