#include <iostream>
#include <string>
using namespace std;


bool b[9][9],B[9][9],l[9][9],a;
string s;

inline void List();
inline void Move();

int main() {
    int n;
    char t;
    cin >> n;
    for (int I=0;I<n;I++) {
        if (I!=0) cout <<"\n";
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                cin >> t;
                if (t == '-') b[i][j] = true;
                else {
                    b[i][j] = false;
                    B[i][j] = (t != 'W');
                }
            }
        }
        cin >> t;
        a = (t != 'W');
        do {
            cin >> t;
            if (t == 'L') {
                List();
                if (s.empty()) {
                    cout << "No legal move.\n";
                } else cout << s << endl;
            } else if (t == 'M') Move();
        } while (t != 'Q');
        for (int i = 1; i < 9; i++) {
            for (int j = 1; j < 9; j++) {
                if (b[i][j]) cout << "-";
                else cout << (B[i][j] ? "B" : "W");
            }
            cout << "\n";
        }
    }
    return 0;
}


inline bool check(int x,int y,int ux,int uy){
    int x0 = x,y0=y,count=0;
    do {
        x +=ux;
        y +=uy;
        count++;
    }while (!b[x][y]&&(B[x][y]!=a)&&(x>0 &&x<9 &&y>0&&y<9));
    if ((x>0 &&x<9 &&y>0&&y<9)&&!b[x][y]&&B[x][y]==a&&count>1)
        l[x0][y0]=true;
    return l[x0][y0];
}


inline void List() {
    s = "";
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            l[i][j] = false;
            if (b[i][j]){
                if (check(i,j,0,-1));
                else if(check(i,j,0,1));
                else if (check(i,j,1,-1));
                else if (check(i,j,1,0));
                else if (check(i,j,1,1));
                else if (check(i,j,-1,-1));
                else if (check(i,j,-1,0));
                else check(i,j,-1,1);
                if (l[i][j]) {
                    if (!s.empty()) s+=" ";
                    s += "(" + to_string(i) + "," + to_string(j) + ")";
                }
            }
        }
    }
}

inline void change(int x,int y,int ux,int uy){
    int count=0;
    do {
        x +=ux;
        y +=uy;
        count++;
    }while (!b[x][y]&&(B[x][y]!=a)&&(x>0 &&x<9 &&y>0&&y<9));
    if ((x>0 &&x<9 &&y>0&&y<9)&&!b[x][y]&&B[x][y]==a)
        for (int i=1;i<count;i++)
            B[x-i*ux][y-i*uy] = a;
}

inline void Move(){
    char X,Y;
    cin >>X>>Y;
    int x = X-'0', y =Y -'0';
    List();
    if (s.empty()) a = !a;
    change(x,y,1,1);
    change(x,y,1,0);
    change(x,y,1,-1);
    change(x,y,0,1);
    change(x,y,0,-1);
    change(x,y,-1,1);
    change(x,y,-1,0);
    change(x,y,-1,-1);
    b[x][y]=false;
    B[x][y]=a;
    int nB=0,nW=0;
    for (int i = 1; i < 9; i++) {
        for (int j = 1; j < 9; j++) {
            if (!b[i][j])
            B[i][j] ? nB++ : nW++;
        }
    }
    cout <<"Black - "<<(nB>9?"":" ")<<nB<<" White - "<<(nW>9?"":" ")<<nW<<endl;
    a = !a;
}

