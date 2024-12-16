#include <bits/stdc++.h>
using namespace std;

using ll = long long;


void solve() {
    int n, m;
    cin >> n >> m;

    vector<int> v(m + 1, m);
    for (int i = 0; i < n; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        v[l] = min(v[l], r);
    }

    ll ans = 0;
    int p = m;
    for (int i = m - 1; i >= 0; i--) {
        p = min(p, v[i]);
        ans += p - i;
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}