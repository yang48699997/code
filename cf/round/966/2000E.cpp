#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    int w;
    cin >> w;
    priority_queue<ll> q;
    for (int i = 0; i < w; i++) {
        ll x;
        cin >> x;
        q.push(x);
    }
    vector<int> cnt;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int l = max(0, i - k + 1);
            l = min(i - l + 1, n - k + 1 - l);
            int r = max(0, j - k + 1);
            r = min(j - r + 1, m - k + 1 - r);
            cnt.push_back(l * r);
        }
    }
    sort(cnt.rbegin(), cnt.rend());
    ll ans = 0;
    for (int i = 0; i < w; i++) {
        ll p = q.top();
        q.pop();
        ans += p * cnt[i];
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