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

pii add(pii a, pii b) {
    return make_pair(a.X + b.X, a.Y + b.Y);
}

int main() {
    pii dir[4];
    dir[0] = make_pair(0, 1);
    dir[1] = make_pair(1, 0);
    dir[2] = make_pair(0, -1);
    dir[3] = make_pair(-1, 0);
    vector<vector<int>> a(35, vector<int>(35, 0));
    int n, m, p;
    cout << "Please input M:";
    cin >> m;
    cout << "Please input N:";
    cin >> n;
    cout << "Please input P:";
    cin >> p;

    for (int i = 0; i <= m + 1; i++) {
        a[i][0] = -1;
        a[i][n + 1] = -1;
    }

    for (int j = 0; j <= n + 1; j++) {
        a[0][j] = a[m + 1][j] = -1;
    }

    pii cur = make_pair(1, 1);
    int cur_dir = 0;
    for (int i = 1; i <= n * m; i++) {
        a[cur.X][cur.Y] = i;
        pii nxt = add(cur, dir[cur_dir]);
        if (a[nxt.X][nxt.Y] != 0) {
            cur_dir++;
            cur_dir %= 4;
            nxt = add(cur, dir[cur_dir]);
        }
        cur = nxt;
    }
    pii ans = make_pair(-1, -1);
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] == p) ans = make_pair(i, j);
            printf(" %3d", a[i][j]);
        }
        printf("\n\n");
    }

    if (ans.X == -1) {
        cout << "P is out of range" << endl;
    }
    else {
        printf("The location of %d is:(%d,%d)\n", p, ans.X, ans.Y);
    }

    return 0;
}