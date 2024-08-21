#include <bits/stdc++.h>
using namespace std;

using ll = long long;

vector<ll> cal_div(ll n) {
    vector<ll> res(1, 1);
    ll cur = n;
    for (ll i = 2; i <= sqrtl(n); i++) {
        if (cur % i) continue;
        int m = res.size();
        ll p = 1;
        while (cur % i == 0) {
            p *= i;
            for (int j = 0; j < m; j++) res.push_back(res[j] * p);
            cur /= i;
        }
    }
    int m = res.size();
    if (cur > 1) for (int i = 0; i < m; i++) res.push_back(res[i] * cur);
    sort(res.begin(), res.end());
    return res;
}

void solve() {
    int a, b, c;
    cin >> a >> b >> c;
    int ans = 0;
    if (a + b == c) {
        cout << "-1\n";
        return;
    }
    if (a + b < c) {
        cout << "0\n";
        return;
    }
    vector<ll> res = cal_div(a + b - c);
    
    auto check = [&](ll x) -> int {
        ll p = x;
        int t1 = a, t2 = b, t3 = c;
        int ok = 1;
        // cerr << p << ":\n";
        while (t1 || t2 || t3) {
            int l1 = t1 % p;
            int l2 = t2 % p;
            int l3 = t3 % p;
            // cerr << l1 << " " << l2 << " " << l3 << "\n";
            // cerr << t1 << " " << t2 << " " << t3 << "\n";
            if ((l1 + l2) % p != l3) ok = 0;
            t1 /= p;
            t2 /= p;
            t3 /= p;
        }
        return ok;
    };
    for (ll p : res) {
        if (p == 1) continue;
        ans += check(p);
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