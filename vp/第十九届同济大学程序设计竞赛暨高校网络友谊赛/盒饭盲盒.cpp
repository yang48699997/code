#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    ll n, a;
    cin >> n >> a;
    ll tot = n * n * n;
    tot -= a * a * a;
    ll p = (n - a) * (n - a) * (n - a);
    ll g = __gcd(tot, p);
    cout << (p / g) << "/" << (tot / g) << "\n";
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