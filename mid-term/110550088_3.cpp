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
    string s;
    map<char, int> m;
    m['I'] = 1; m['V'] = 5; m['X'] = 10; m['L'] = 50; m['C'] = 100; m['D'] = 500; m['M'] = 1000;
    int ans = 0;
    cout << "Roman numeral: ";
    cin >> s;
    int sz = s.size();
    for (int i = sz - 1; i >= 0; i--) {
        // cout << s[i] << " " << m[s[i]] << " " << ans << endl;
        if (s[i] == 'I') {
            ans++;
        }
        else if (s[i] == 'V' || s[i] == 'X') {
            if (i > 0 && s[i-1] == 'I') {
                ans += m[s[i]] - 1;
                i--;
            }
            else {
                ans += m[s[i]];
            }
        }
        else if (s[i] == 'L' || s[i] == 'C') {
            if (i > 0 && s[i - 1] == 'X') {
                ans += m[s[i]] - 10;
                i--;
            }
            else {
                ans += m[s[i]];
            }
        }
        else if (s[i] == 'D' || s[i] == 'M') {
            if (i > 0 && s[i - 1] == 'C') {
                ans += m[s[i]] - 100;
                i--;
            }
            else {
                ans += m[s[i]];
            }
        }
    }

    cout << "This roman numeral is ";
    cout << ans << "." << endl;

    return 0;
}