#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;

    vector<vector<int>> p(n);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        x--;
        p[x].push_back(i + 1);
    }

    ll ans = 0;
    for (auto &e : p) {
        int m = e.size();
        for (int i = 0; i < m; i++) {
            int l = 0, r = n + 1;

            if (i) l = e[i - 1];
            ans += 1LL * (e[i] - l) * (r - e[i]);
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}