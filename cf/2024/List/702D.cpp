#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll d, k, a, b, t;
    cin >> d >> k >> a >> b >> t;

    ll ans = d % k * a;
    ll lef = ans / a;

    if (lef == 0) ans -= t;
    ans += d / k * (a * k + t);

    ll res1 = b * d;
    ll res2 = d / k * (a * k + t) - t + lef * b;
    if (d / k == 0) res2 += t;
    ll res3 = min(d, k) * a + (d - min(d, k)) * b;
    
    cout << min({ans, res1, res2, res3}) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}