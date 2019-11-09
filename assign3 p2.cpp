#include <iostream>

using namespace std;

int n;
string name[100];
char na[101];
string sid[100];
char s[9];


void search(string key) {
	bool valid = true;
	for (int i = 0; key[i] && valid; i++) {
		if (key[i] - '0' > 10 || key[i] - '0' < -1) {
			cout << "Invalid search input.\n";
			valid = false;
		}
	}
	if (valid) {
		int out[100];
		int count = 0;
		for (int i = 0; i < n; i++) {
			int m = 0;
			for (int j = 0; j < 8; j++) {
				if (sid[i][j] == key[m])
					m++;
				else m = 0;
				if (!key[m]) {
					out[count] = i;
					count++;
					break;
				}
			}
		}
		if (count) {
			cout << "Search result: \n";
			for (int i = 0; i < count; i++) {
				for (int k = 0; name[out[i]][k]; k++)
					cout << name[out[i]][k];
				cout << " ";
				for (int k = 0; k < 8; k++)
					cout << sid[out[i]][k];
				cout<< endl;
			}
		}
		else cout << "No result.\n";
	}
}

int main() {
	bool end = true;
	cout << "Input the number of students:\n";
	cin >> n;
	if (n > 100) cout << "The number of students must be no larger than 100!";
	else {
		cout << "Input the student Information:\n";
		for (int i = 0; i < n; i++) {
			cin >> na >> s;
			if (s[8] || !s[7]) {
				cout << "The length of student ID must be 8!";
				end = false;
				break;
			}
			name[i] = na;
			sid[i] = s;
		}

		if (end) {
			string tem;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n - 1; j++) {
					if (name[j] > name[j + 1]) {
						tem = name[j];
						name[j] = name[j + 1];
						name[j + 1] = tem;
						tem = sid[j];
						sid[j] = sid[j + 1];
						sid[j + 1] = tem;

					}
				}
			}

			cout << "Input the search keyword:\n";
			char k[9];
			cin >> k;
			string key1 = k;
			search(key1);

			cout << "Delete the student with SID: \n";
			char d[9];
			cin >> d;
			string del = d;
			for (int i = 0; i < n; i++) {
				if (del == sid[i]) {
					for (int j = i; j < n - 1; j++) {
						sid[j] = sid[j + 1];
						name[j] = name[j + 1];
					}
					n--;
					break;
				}
				if (i == n - 1) cout << "No result.\n";
			}

			cout << "Input the search keyword:\n";
			char k2[9];
			cin >> k2;
			string key2 = k2;
			search(key2);
		}
	}
	return 0;
}