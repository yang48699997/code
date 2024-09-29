#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    vector<vector<int>> e(20, vector<int> (n + 1));
    for (int i = 0; i < n; i++) {
        ll now = pre[i];
        int j = upper_bound(pre.begin(), pre.end(), now + k) - pre.begin();
        e[0][i] = j - 1;
    }
    e[0][n] = n;
    for (int k = 1; k < 20; k++) {
        e[k][n] = n;
        for (int i = 0; i < n; i++) {
            e[k][i] = e[k - 1][e[k - 1][i]];
        }
    }
    int ans = 0;
    for (int l = 0; l < n; l++) {
        int r = l;
        for (int i = 0; i < 20; i++) {
            if (1 << i & m) r = e[i][r];
        }
        ans = max(ans, r - l);
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