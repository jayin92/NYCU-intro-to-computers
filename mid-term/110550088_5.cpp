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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    for (int i = 0; i < 5; i++) {
        string a, b;
        cin >> a >> b;
        int sza = a.size();
        int szb = b.size();
        int n = sza + szb + 5;
        vector<int> res(n, 0);
        vector<int> aa(sza, 0);
        vector<int> bb(szb, 0);
        for (int i = 0; i < sza; i++) {
            aa[i] = a[sza - 1 - i] - '0';
        }
        for (int i = 0; i < szb; i++) {
            bb[i] = b[szb - 1 - i] - '0';
        }
        for (int j = 0; j < szb; j++) {
            for (int i = 0; i < sza; i++) {
                res[i + j] += bb[j] * aa[i];
            }
        }
        int carry = 0;
        for (int i = 0; i < n; i++) {
            res[i] += carry;
            carry = res[i] / 10;
            res[i] %= 10;
        }
        bool flag = true;
        for (int i = n - 1; i >= 0; i--) {
            if (flag) {
                if (res[i] != 0) {
                    cout << res[i];
                    flag = false;
                }
            }
            else {
                cout << res[i];
            }
        }

        if (flag) {
            cout << 0;
        }
        cout << endl;
    }

    return 0;
}