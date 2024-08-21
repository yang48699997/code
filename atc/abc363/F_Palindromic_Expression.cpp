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
    sort(res.begin(), res.end());
    return res;
}

bool is_valid(string &s) {
    for (char c : s) {
        if (c == '0') return false;
    }
    return s == string(s.rbegin(), s.rend());
}

ll to_ll(string &s) {
    ll res = 0;
    for (char c : s) {
        res = res * 10 + c - '0';
    }
    return res;
}
void solve() {
    ll n;
    cin >> n;
    vector<ll> f = cal_div(n);
    vector<ll> div;
    for (int i = 1; i < f.size(); i++) {
        ll temp = f[i];
        bool ok = 1;
        while (f[i]) {
            if (f[i] % 10 == 0) ok = 0;
            f[i] /= 10;
        }
        if (ok) div.push_back(temp);
    }
    int m = div.size();

    map<ll, string> mp;

    auto dfs = [&](auto self, ll x) -> string {
        if (mp.count(x)) return mp[x];
        string s = to_string(x);
        if (is_valid(s)) {
            mp[x] = s;
            return s;
        }
        for (int i = 0; i < m; i++) {
            if (x % div[i]) continue;
            string cur = to_string(div[i]);
            string rev = string(cur.rbegin(), cur.rend());
            if (x / div[i] % to_ll(rev)) continue;
            string res = self(self, x / div[i] / to_ll(rev));
            if (res != "") {
                cur += "*" + res + "*" + rev;
                mp[x] = cur;
                return cur;
            }
        }
        mp[x] = "";
        return "";
    };

    string ans = dfs(dfs, n);
    cout << (ans == "" ? "-1" : ans) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}