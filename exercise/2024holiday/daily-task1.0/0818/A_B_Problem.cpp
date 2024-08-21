#include <bits/stdc++.h>
using namespace std;

using ll = unsigned int;

void solve() {
    int n;
    cin >> n;
    vector<ll> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    int p = 0;
    vector<ll> ans(n);
    ll base = a.back() ^ b.back();

    for (int k = 0; k < 32; k++) {
        ll now = 0;
        ll q = 1;
        if (base >> k & 1) now = 1;
        if (p) now ^= 1;
        ans[0] += (now << k ^ (q << k & a[0])) + (now << k ^ (q << k & b[0]));
        for (int i = 1; i < n; i++) {
            now = ans[i - 1];
            now &= q << k;
            ans[i] += (now ^ (q << k & a[i])) + (now ^ (q << k & b[i]));
        } 
        if (k < 31 && ans.back() >> k >> 1 & 1) p = 1;
        else p = 0;
    }

    for (int i = 0; i < n; i++) {
        cout << ans[i] << "\n";
    }
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