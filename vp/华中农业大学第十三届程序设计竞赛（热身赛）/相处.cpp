#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll c;
    cin >> n >> c;
    vector<ll> p(n + 1);
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) {
        ll b;
        cin >> b;
        p[i + 1] = abs(a[i] - b) + p[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        ans = max(ans, (int)(upper_bound(p.begin(), p.end(), p[i] + c) - p.begin()) - i - 1);
    }


    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}