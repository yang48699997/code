#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<ll> r(n), q(n);
    for (int i = 0; i < n; i++) {
        cin >> q[i] >> r[i];
    }

    int ask;
    cin >> ask;
    while (ask--) {
        ll t, d;
        cin >> t >> d;
        t--;

        ll p = r[t];
        if (d % q[t] > r[t]) p += q[t];

        cout << d / q[t] * q[t] + p << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}