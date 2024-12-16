#include <bits/stdc++.h>
using namespace std;

using ll = long long;

ll q(ll l, ll r) {
    cout << "xor " << l << " " << r << endl;
    ll res;
    cin >> res;
    return res;
}

void solve() {
    ll n;
    cin >> n;

    ll a = 0;
    ll l = 1, r = n;

    if (q(1, n) == 0) {
        r = 1;
        ll res;
        while (1) {
            res = q(1, r);
            if (res == 0) r <<= 1;
            else break;
        }
        ll res2 = q(r, r);
        if (res2 == res) a = res;
        else a = res2 ^ res;
    } else {
        while (l <= r) {
            ll mid = (l + r) / 2;
            ll res = q(1, mid);
            if (res == 0) {
                l = mid + 1;
            } else r = mid - 1;
        }
        a = l;
    }
    
    
    l = a + 1, r = n;
    while (l <= r) {
        ll mid = (l + r) / 2;
        ll res = q(1, mid);
        res ^= a;
        if (res == 0) l = mid + 1;
        else r = mid - 1;
    }
    ll b = l;

    ll c = a ^ b ^ q(1, n);

    cout << "ans " << a << " " << b << " " << c << endl;
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