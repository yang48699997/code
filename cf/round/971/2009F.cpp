#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    vector<ll> pre(n * 2 + 1);
    for (int i = 1; i <= n * 2; i++) pre[i] = pre[i - 1] + a[(i - 1) % n];
    auto cal = [&](ll x) -> ll {
        if (x == 0) return 0LL;
        ll res = x / n * pre[n];
        ll lef = x % n;
        ll p = x / n;
        res += pre[x % n + p] - pre[p];
        return res;        
    };
    while (q--) {
        ll l, r;
        cin >> l >> r;
        cout << cal(r) - cal(l - 1) << "\n";
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