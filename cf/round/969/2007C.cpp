#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    int g = __gcd(a, b);
    vector<int> p(n);
    int mx = 0, mi = g - 1;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        p[i] %= g;
        mx = max(p[i], mx);
    }
    sort(p.begin(), p.end());
    int m = unique(p.begin(), p.end()) - p.begin();
    p.resize(m);
    int ans = g;
    for (int i = 0; i < p.size(); i++) {
        ans = min(ans, mx - p[i]);
        mx = p[i] + g;
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