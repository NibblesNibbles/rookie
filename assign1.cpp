#include <iostream>
#include "today.h"
using namespace std;

int main(){

    //Get the date
    int cy = ThisYear();
    int cm = ThisMonth();
    int cd = ThisDay();
    int by,bm,bd;
    cout << "Please enter your birth date (yyyy mm dd) : \n";
    cin >> by >> bm >>bd;


    //Verify whether the day is valid
    bool valid = false , display = false;
   if (by < 1900) {
        cout << "Year not in range!!"<<endl;
    }else if (bd==29 && bm==2 && by%4==0 && by!=1900){
        valid = true ;
    }else {
        switch (bm) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (bd <= 31 && bd >= 1)
                    valid = true;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (bd<= 30 && bd >=1)
                    valid = true;
                break;
            case 2 :
                if (bd<= 28 && bd >=1)
                   valid = true;
                break;
        }
    }

    if (valid) {
            if (by > cy){
                cout << "You are not born yet!!"<<endl;
            }else if (by == cy && bm > cm){
                cout << "You are not born yet!!"<<endl;
            }else if (by == cy && bm == cm && bd > cd){
                cout << "You are not born yet!!"<<endl;
            }else
                display = true;
    } else if(by>=1900) {
        cout << "Invalid date!!"<<endl;
    }


    if (display){
        //Calculate week
        int ay,am;
        if (bm==1 ||bm ==2){
            ay = by -1;
            am = bm +10;
        }else {
            ay = by;
            am = bm -2;
        }
        int century = ay/100  ;
        int sum = bd + +ay + ay/4 + century/4 + (am*31)/12 -century;
        int week = sum%7;

        //Output the birth date and week
        if (bm==cm && bd==cd && by==cy){
            cout <<"Happy Birthday!!"<<endl;
            cout << "Today is ";
        }else {
            cout << "Your birthday was on "<<bd;
            if (bd==1 || bd==21 || bd==31) cout<<"st ";
            else if (bd==2 || bd==22) cout <<"nd ";
            else if (bd==3 || bd== 23) cout <<"rd ";
            else cout <<"th ";
            switch (bm){
                case 1: cout <<"January"; break;
                case 2: cout <<"February"; break;
                case 3: cout <<"March"; break;
                case 4: cout <<"April"; break;
                case 5: cout <<"May"; break;
                case 6: cout <<"June"; break;
                case 7: cout <<"July"; break;
                case 8: cout <<"August"; break;
                case 9: cout <<"September"; break;
                case 10: cout <<"October"; break;
                case 11: cout <<"November"; break;
                case 12: cout <<"December"; break;
            }
            cout <<" "<<by<<"."<<endl;
            cout << "It was a ";
        }
        switch (week){
            case 0: cout<<"Sunday"; break;
            case 1: cout<<"Monday"; break;
            case 2: cout<<"Tuesday"; break;
            case 3: cout<<"Wednesday"; break;
            case 4: cout<<"Thursday"; break;
            case 5: cout<<"Friday"; break;
            case 6: cout<<"Saturday"; break;
        }
        cout <<"."<<endl;


        //Calculate lucky number
        int d1,d2,d3,d4,d5,d6,d7,d8,sum1,sum2,lucky;
        d1 = by/1000;
        d2 = by/100 - 10*d1;
        d3 = (by%100)/10;
        d4 = by%10;
        d5 = bm/10;
        d6 = bm%10;
        d7 = bd/10;
        d8 = bd%10;
        sum1 = d1+d2+d3+d4+d5+d6+d7+d8;
        sum2 = sum1/10 +sum1%10;
        lucky = sum2/10 + sum2%10;
        cout << "Your lucky number is "<<lucky<<"."<<endl;
    }
    return 0;
}