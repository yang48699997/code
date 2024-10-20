#include <bits/stdc++.h>
using namespace std;

using ll = long long;

pair<int, int> cal(int n, int m, int xx) {

    auto cal = [&](ll x) -> ll {
        if (x == 0) return 0;
        ll p1 = 2 * (n + m) - 4;
        ll p2 = p1 - (x - 1) * 8;
        return (p1 + p2) / 2 * x;
    };
    
    ll l = 1, r = n / 2;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll res = cal(mid);
        if (res >= xx) r = mid - 1;
        else l = mid + 1;
    }

    ll lef = xx - cal(r);
    ll x = m - 2 * r;
    ll y = n - 2 * r;
    if (x >= lef) {
        return {r + 1, r + lef};
    }
    lef -= x - 1;
    if (y >= lef) {
        return {r + lef, r + x}; 
    }
    lef -= y - 1;
    if (x >= lef) {
        return {n - r, r + x - lef + 1};
    }
    lef -= x - 1;
    return {n - r - lef + 1, r + 1};
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> g(n + 1, vector<int> (m + 1));
    for (int i = 1; i <= n * m; i++) {
        auto [x, y] = cal(n, m, i);
        g[x][y] = i;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cout << g[i][j] << " \n"[j == m];
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}