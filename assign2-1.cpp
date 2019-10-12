#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    cout << "Input the number of dice(s): ";
    int N;
    cin >> N;
    int sum = 0,face;
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
    for (int i = N; i < sum + 1; i++) {
        cout << "Probability of " << setw(width) << i
             << " = " << result[N - 1][i] << "/" << total << endl;
    }
    return 0;
}