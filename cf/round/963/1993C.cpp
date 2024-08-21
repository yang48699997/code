#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<int> b;
    map<int, int> mp;
    ll ans = 0;
    for (int i : a) {
        b.push_back(i % (k * 2));
        mp[i % (k * 2)] = max(mp[i % (k * 2)], i / (k * 2) * k * 2);
        ans = max(ans, (ll)i / (k * 2) * k * 2);
    }
    sort(b.begin(), b.end());
    int m = unique(b.begin(), b.end()) - b.begin();
    b.resize(m);
    vector<int> pre(m + 1);
    vector<int> suf(m + 1);
    for (int i = 0; i < m; i++) {
        pre[i + 1] = pre[i];
        suf[m - i - 1] = suf[m - i];
        suf[m - i - 1] = max(suf[m - i - 1], mp[b[m - i - 1]]);
        pre[i + 1] = max(pre[i + 1], mp[b[i]]);
    }
    // for (int i = 0; i <= m; i++) {
    //     cerr << pre[i] << " " << suf[i] << "\n";
    // }
    ll res = 1e18;
    if (b.back() - b[0] < k) {
        ans += b.back();
        res = min(res, ans);
    } 
    int pr = b[0];
    for (int i = 1; i < m; i++) {
        if (pr + k < b[i]) {
            ans = pr;
            ans += max(pre[i], suf[i] + k * 2);
            res = min(res, (ll) ans);
        }
        pr = b[i];
    }
    if (res == 1e18) cout << "-1\n";
    else cout << res << "\n";
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