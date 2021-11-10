#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#define X first
#define Y second

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

double dis(double x1, double y1, double x2, double y2) {
	double res = (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);

	return res;
}

int main() {
	double ax, ay, bx, by, cx, cy;
	double eps = 1e-7;
	cout << "Input the first point in R^2 space x,y = ";
	cin >> ax >> ay;
	cout << "Input the second point in R^2 space x,y = ";
	cin >> bx >> by;
	cout << "Input the third point in R^2 space x,y = ";
	cin >> cx >> cy;

	double a, b, c;
	a = dis(ax, ay, bx, by);
	b = dis(ax, ay, cx, cy);
	c = dis(bx, by, cx, cy);

	if (a < b) swap(a, b);
	if (b < c) swap(b, c);
	if (a < b) swap(a, b);

	// cout << a << " " << b << " " << c << endl;

	cout << "Output:" << endl;
	if (sqrt(a) >= sqrt(b) + sqrt(c) || fabsl(sqrt(a) - (sqrt(b) + sqrt(c))) < eps) {
		cout << "These three point cannot form a triangle." << endl;
		return 0;
	}


	if (fabsl(a - (b + c)) < eps) {
		cout << "These three point form a right triangle." << endl;
	}
	else if (a > b + c) {
		cout << "These three point form an obtuse triangle." << endl;
	}
	else if (a < b + c) {
		cout << "These three point form an acute triangle." << endl;
	}

	return 0;
}