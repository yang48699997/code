#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int mod = 1e9 + 7;

int T;
void solve() {
    string s;
    cin >> s;
    int n = s.length();
    vector<int> pre(n + 1);
    for (int i = 0; i < n; i++) {
        pre[i + 1] = pre[i];
        if (s[i] == '0') pre[i + 1]++;
        else pre[i + 1]--;
    }
    map<int,ll> mp;
    mp[0]++;
    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        ans += (n - i + 1) * mp[pre[i]];
        ans %= mod;
        mp[pre[i]] += i + 1;
        mp[pre[i]] %= mod;
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}