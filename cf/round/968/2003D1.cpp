#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> l(n);
    vector<int> have(n);
    vector<int> next(n);
    map<int, int> mp;
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
        mx = max(mx, have[i]);
        mp[have[i]] = max(mp[have[i]], next[i]);
    }

    vector<vector<int>> e(len + 10);
    for (int i = 0; i < n; i++) {
        e[have[i]].push_back(next[i]);
    }
    vector<int> v(len + 10);
    for (int i = 0; i < n; i++) {
        v[have[i]] = 1;
    }
    int res = 0;
    for (int i = 0; i < len + 10; i++) {
        if (v[i]) {
            res = max(res, i);
            for (int nxt : e[i]) {
                v[nxt] = 1;
            }
        }
    }
    ll ans = (ll)min(res + 1, m + 1) * res;
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