#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    ll x;
    cin >> n >> x;
    ll ans = 0;
    x = abs(x);
    for (int i = 0; i < n; i++) {
        int p;
        cin >> p;
        p = abs(p);
        if (x == 0) continue;
        x -= p;
        x = abs(x);
        ans += abs(p);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}