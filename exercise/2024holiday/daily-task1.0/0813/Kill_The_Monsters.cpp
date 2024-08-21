#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, k;
    cin >> n >> k;
    priority_queue<int> q;
    int mx = 0;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        mx = max(mx, x);
        q.push(x);
    }
    if (k == 1) {
        cout << mx << "\n";
        return;
    }
    ll ans = 1e18;
    ll cnt = 0;
    while (!q.empty()) {
        int p = q.top();
        q.pop();
        ans = min(ans, cnt + p);
        p /= k;
        if (p) q.push(p);
        cnt++;
    }
    ans = min(ans, cnt);
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}