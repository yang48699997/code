#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const ll inf = 1e18;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];

    ll ans = inf;

    priority_queue<ll> pa, pb;
    vector<ll> prea(n, inf), preb(n, inf);
    ll res = 0;
    for (int i = 0; i < m; i++) {
        pa.push(a[i]);
        res += a[i];
    }

    prea[m - 1] = res;
    for (int i = m; i < n; i++) {
        res -= pa.top();
        ll p = min(a[i], pa.top());
        pa.pop();
        res += p;
        pa.push(p);
        prea[i] = res;
    }

    res = 0;
    for (int i = n - 1; i >= n - m; i--) {
        res += b[i];
        pb.push(b[i]);
    }
    preb[n - m] = res;
    for (int i = n - m - 1; i >= 0; i--) {
        res -= pb.top();
        ll p = min(b[i], pb.top());
        pb.pop();
        res += p;
        pb.push(p);
        preb[i] = res;
    }

    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, prea[i] + preb[i + 1]);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}