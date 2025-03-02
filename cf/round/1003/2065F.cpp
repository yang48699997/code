#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    vector<vector<int>> e(n);
    string ans = string(n, '0');

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        e[u].push_back(v);
        e[v].push_back(u);
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        v[a[i]] = 1;
        for (int nxt : e[i]) {
            if (v[a[nxt]]) ans[a[nxt]] = '1';
            else v[a[nxt]] = 1;
        }

        v[a[i]] = 0;
        for (int nxt : e[i]) {
            v[a[nxt]] = 0;
        }
    }

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