#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int m;
    cin >> m;
    vector<vector<int>> d(m);
    map<int, int> mp;
    for (int i = 0; i < m; i++) {
        int n;
        cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            cin >> x;
            d[i].push_back(x);
            mp[x] = i;
        }
    }
    vector<int> ans(m, -1);
    for (auto [x, d] : mp) {
        ans[d] = x;
    }
    for (int i = 0; i < m; i++) {
        if (ans[i] == -1) {
            cout << "-1\n";
            return;
        }
    }
    for (int i = 0; i < m; i++) {
        cout << ans[i] << " \n"[i == m - 1];
    }
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