#include <iostream>
#include <iomanip>
using namespace std;

void simplify(int a,int b);

int main() {
    cout << "Input the number of dice(s): ";
    int N;
    cin >> N;
    double face;
    int sum = 0, count = 0;
    long long total = 1;
    long long result[12][145] = {0};

    for (int i = 0; i < N; i++) {
        cout << "Input the number of faces for the " << i + 1;
        if (i == 0) cout << "st";
        else if (i == 1) cout << "nd";
        else if (i == 2) cout << "rd";
        else cout << "th";
        cout << " dice: ";
        cin >> face;
        int f = face;
        if (f != face || face <= 0 || face > 12) {
            cout << "Error: input value should be integer in range 1..12\n";
            i--;
            continue;
        }
        if (face != 1) count++;
        total *= face;
        sum += face;
        if (i == 0) {
            for (int j = 1; j < face + 1; j++) {
                result[i][j] = 1;
            }
        } else
            for (int j = 1; j < face + 1; j++) {
                for (int k = i + 1; k < sum + 1; k++)
                    if (k - j - i >= 0)
                        result[i][k] += result[i - 1][k - j];
            }
    }

    int width = 1;
    if (sum > 9) width = 2;
    if (sum > 99) width = 3;

    if (count > 1) {
        int x = (N + sum) % 2;
        for (int i = (N + sum + x) / 2; i < sum + 1; i++) {
            cout << "Probability of " << setw(width) << sum + N - i << " = ";
            simplify(total, result[N - 1][sum + N - i]);
            if (i != sum + N - i) {
                cout << "Probability of " << setw(width) << i << " = ";
                simplify(total, result[N - 1][i]);
            }
        }
    } else
        for (int i = N; i < sum + 1; i++) {
            cout << "Probability of " << setw(width) << i << " = ";
            simplify(total, result[N - 1][i]);
        }
    return 0;
}

void simplify(int a,int b) {
    int mod=a%b ;
    int c = a, d = b;
    while (mod != 0) {
        c = d;
        d = mod;
        mod = c%d;
    }
    cout << b / d << "/" << a / d << endl;
}
