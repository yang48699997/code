#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mod = 1e9 + 7;
//using ll = long long;
ll powMod(ll x, ll y) {
    ll res = 1;
    while (y) {
        if(y & 1)res = res * x % mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};
void solve() {
    int n;
    string s;
    cin >> n >> s;
    vector<int> cnt(26);
    for (char c : s) {
        cnt[c - 'A']++;
    }   
    int mx = 0;
    for (int i : cnt) mx = max(mx, i);
    int c = 0;
    for (int i = 0; i < 26; i++) if (cnt[i] == mx) c++;
    cout << powMod(c, n) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}