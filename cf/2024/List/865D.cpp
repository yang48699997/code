#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    ll ans = 0;
    priority_queue<ll, vector<ll>, greater<ll>> q;
    for (int i = 0; i < n; i++) {
        if(!q.empty() && a[i] > q.top()) {
            ans += a[i] - q.top();
            q.pop();
            q.push(a[i]);
        }
        q.push(a[i]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}