#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int  mod  = 2097152;

void solve() {
    int q;
    cin >> q;
    ll ans = 0;
    const int mx = 50;
    vector<ll> p(30);
    vector<ll> sum(30);
    vector<int> a;
    vector<ll> power(mx + 1, 1);
    for (int i = 1; i <= mx; i++) {
        power[i] = power[i - 1] * 2 % mod;
    }
    while (q--) {
        int t, v;
        cin >> t >> v;
        for (int j = 0; j < t; j++) {
            
        }
        ans = 0;
        for (int i = 0; i < mx; i++) {

        }
        a.push_back(v);
        ans %= mod;
        // cout << ans << "\n";
    }
    int cur = mod;
    string s;
    int cnt = 0;
    while (cur) {
        cnt++;
        int p = cur % 2;
        s += (p + '0');
        cur /= 2;
    }
    reverse(s.begin(), s.end());
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}