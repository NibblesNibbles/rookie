#include <iostream>
using namespace std;

int main() {
	int d1, h1, m1, s1, d2, h2, m2, s2;
	cout << "For start time, please enter the following information:\n";
	cout << "Enter the start day (a number in range from 1 to 31): ";
	cin >> d1;
	cout << "Enter the start hour (a number in range from 0 to 23): ";
	cin >> h1;
	cout << "Enter the start minute (a number in range from 0 to 59): ";
	cin >> m1;
	cout << "Enter the start second (a number in range from 0 to 59): ";
	cin >> s1;
	cout << "For end time, please also enter the similar information:\n";
	cout << "Enter the end day (a number in range from 1 to 31): ";
	cin >> d2;
	cout << "Enter the end hour (a number in range from 0 to 23): ";
	cin >> h2;
	cout << "Enter the end minute (a number in range from 0 to 59): ";
	cin >> m2;
	cout << "Enter the end second (a number in range from 0 to 59): ";
	cin >> s2;

	int d = d2 - d1;
	int h = h2 - h1;
	int m = m2 - m1;
	int s = s2 - s1;

	if (s < 0) {
		s += 60;
		m -= 1;
	}
	if (m < 0) {
		m += 60;
		h -= 1;
	}
	if (h < 0) {
		h += 24;
		d -= 1;
	}
	
	cout << "The time difference is: " << d << " day(s), " << h << " hour(s), " << m << " minute(s), and " << s << " second(s).\n";
	return 0;
}