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

int main() {
	vector<bool> p(1e5, true);
	p[2] = p[3] = p[5] = true;
	for (int i = 2; i < 1e5; i++) {
		if (p[i]) {
			for (int j = 2*i; j < 1e5; j += i) {
				p[j] = false;
			}
		}
	}
	cout << "Input an integer:";
	int n;
	cin >> n;
	cout << "Output:" << endl;
	int cnt = 0;
	for (int i = 2; i <= n; i++) {
		if (p[i]) {
			cout << i << " ";
			cnt++;
			if (cnt == 10) {
				cout << endl;
				cnt = 0;
			}
		}
	}
    
    return 0;
}