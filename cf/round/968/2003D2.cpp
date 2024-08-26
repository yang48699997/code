#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> l(n);
    vector<int> have(n);
    vector<int> next(n);
    int mx = 0;
    int len = 0;

    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        len = max(len, p);
        while (p--) {
            int x;
            cin >> x;
            l[i].push_back(x);
        }
        sort(l[i].begin(), l[i].end());
        p = unique(l[i].begin(), l[i].end()) - l[i].begin();
        l[i].resize(p);
        have[i] = p;
        for (int j = 0; j < p; j++) {
            if (l[i][j] != j) {
                have[i] = j;
                break;
            }
        }
        l[i].push_back(have[i]);
        sort(l[i].begin(), l[i].end());
        next[i] = p + 1;
        for (int j = 0; j <= p; j++) {
            if (l[i][j] != j) {
                next[i] = j;
                break;
            }
        }
    }

    vector<vector<int>> e(len + 10);
    for (int i = 0; i < n; i++) {
        e[have[i]].push_back(next[i]);
    }
    vector<int> v(len + 10);
    for (int i = 0; i < n; i++) {
        v[have[i]]++;
    }
    int res = 0;
    for (int i = 0; i < len + 10; i++) {
        if (v[i]) res = max(res, i);
        if (v[i] > 1) {
            for (int nxt : e[i]) {
                v[nxt] += 2;
            }
        }
    }
    ll ans = 0;
    vector<vector<int>> pre(len + 10);
    vector<int> ok(len + 10);
    for (int i = 0; i < n; i++) {
        pre[next[i]].push_back(have[i]);
        ok[next[i]] = next[i];
    }
    ok[mx] = 1;
    for (int i = len + 9; i >= 0; i--) {
        if (ok[i]) {
            for (int nxt : pre[i]) {
                ok[nxt] = max(ok[nxt], ok[i]);
            }
        }
    }
    for (int i = 0; i <= min(res, m); i++) {
        ans += max(res, ok[i]);
    }
    ll lef = min(res, m);
    ans += (ll)m * (m + 1) / 2 -  lef * (lef + 1) / 2;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}