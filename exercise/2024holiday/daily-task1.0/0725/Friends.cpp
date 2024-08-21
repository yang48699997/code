#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> l(n), r(n);
    for (int i = 0; i < n; i++) {
        e[i].push_back(i);
        l[i] = r[i] = i;
        sort(e[i].begin(), e[i].end());
        int p = 0;
        for (int j = 0; j < e[i].size(); j++) {
            if (e[i][j] == i) {
                p = j;
                break;
            }
        }
        for (int j = p - 1; j >= 0; j--) {
            if (e[i][j] == l[i] - 1) l[i]--;
            else break;
        }
        for (int j = p + 1; j < e[i].size(); j++) {
            if (e[i][j] == r[i] + 1) r[i]++;
            else break;
        }
    }
    vector<vector<int>> mi(n, vector<int> (21));
    vector<int> lg(n + 1);
    for (int i = 0; i < n; i++) {
        mi[i][0] = r[i];
        if (i > 1) {
            lg[i] = lg[i / 2] + 1;
        }
    }
    lg[n] = lg[n / 2] + 1;
    for (int j = 1; j <= 20; j++) {
        int p = (1 << j >> 1);
        for (int i = 0; i < n; i++) {
            mi[i][j] = min(mi[i][j - 1], mi[min(n - 1, i + p)][j - 1]);
        }
    }
    ll ans = 0;
    // for (int i = 0; i < n; i++) {
    //     cerr << l[i] << " " << r[i] << "\n";
    // }
    for (int i = 0; i < n; i++) {
        int p = r[i];
        int g = lg[p - i + 1];
        int res = min(p, mi[i][g]) - i + 1;
        ans += res;
    }
    cout << ans << "\n";
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}