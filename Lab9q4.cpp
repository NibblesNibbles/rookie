#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Triangle {
private:
	double a, b, c,area; 

public:
	Triangle() {
		a = b = c = area = 0;
	}
	void computeArea() {
		double s = (a + b + c) / 2;
		area = sqrt(s * (s - a) * (s - b) * (s - c));
	}
	Triangle(double A, double B, double C) {
		a = A;
		b = B;
		c = C;
		computeArea();
	}
	void set(double A, double B, double C) {
		a = A;
		b = B;
		c = C;
		computeArea();
	}
	
	double getArea() {
		return area;
	}
};

int main() {
	Triangle tri[10];
	cout << fixed << setprecision(2);
	double A, B, C;
	cout << "Enter	a	number	between	1	and	10:\n";
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "Enter	the	sides	of	triangle	" << i + 1 << ":\n";
		cin >> A >> B >> C;
		tri[i].set(A, B, C);
	}

	for (int i = 0; i < n; i++) {
		cout << "Area	of	triangle " << i + 1 << ": " << tri[i].getArea()<<endl;
	}
	int m = 0;
	for (int i = 1; i < n; i++) {
		if (tri[i].getArea() > tri[m].getArea()) m = i;
	}
	cout << "Triangle	" << m + 1 << "	has	the	largest	area:	" << tri[m].getArea();
	return 0;
}

