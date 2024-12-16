#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, v;
    cin >> n >> m >> v;
    vector<ll> a(n);
    ll ans = -1;

    for (int i = 0; i < n; i++) cin >> a[i];
    
    vector<int> l;
    ll now = 0;
    vector<ll> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i] + a[i];
    }

    for (int i = 0; i < n; i++) {
        now += a[i];
        if (now >= v) {
            now = 0;
            l.push_back(i);
        }
    }
    now = 0;
    vector<int> r;
    for (int i = n - 1; i >= 0; i--) {
        now += a[i];
        if (now >= v) {
            now = 0;
            r.push_back(i);
        }
    }
    reverse(r.begin(), r.end());
    if (r.size() >= m) ans = pre[r[r.size() - m]];

    for (int i = 0; i < l.size(); i++) {
        int cl = l[i];
        if (i == m - 1) {
            ans = max(ans, pre[n] - pre[l[i] + 1]);
            continue;
        }
        if (r.size() < m - i - 1) {
            continue;
        }
        int cr = r[r.size() - (m - i - 1)];
        if (cl >= cr) continue;
        ans = max(ans, pre[cr] - pre[cl + 1]);
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