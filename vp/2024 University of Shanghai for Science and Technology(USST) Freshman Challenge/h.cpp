#include <bits/stdc++.h>
using namespace std;

using ll = long long;

string f(string s) {
    int n = s.size();
    string res = string(n, '0');
    vector<char> p;
    for (int i = 0; i < 10; i++) {
        p.push_back((char)('0' + i));
    }
    for (int i = 0; i < 6; i++) {
        p.push_back((char)('A' + i));
    }
    map<char, int> mp;
    for (int i = 0; i < 16; i++) {
        mp[p[i]] = i;
    }
    int ok = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            int now = mp[s[i]];
            if (now != 0) ok = 1;
            res[i] = p[(16 - now) % 16];
        } else {
            int now = (mp[s[i]] + ok) % 16;
            if (now != 0) ok = 1;
            res[i] = p[(16 - now) % 16];
        }
    }
    reverse(res.begin(), res.end());
    while (res.back() == '0') res.pop_back();
    reverse(res.begin(), res.end());
    return res;
}

void solve() {
    int n;
    cin >> n;
    map<string, int> cnt;
    map<string, int> mp;
    ll ans = 0;
    vector<string> pp(n);
    for (int i = 0; i < n; i++) {
        cin >> pp[i];
        if (pp[i][0] != '-') {
            cnt[pp[i]]++;
        } else {
            string res = pp[i].substr(1);
            mp[res]++;
        }
    }
    for (int i = 0; i < n; i++) {
        string s = pp[i];
        if (s[0] != '-') {
            ans += cnt[s] - 1;
        } else {
            s = s.substr(1);
            string res = f(s);
            ans += mp[res];
            if (res == s) ans--;
            reverse(res.begin(), res.end());
            while (res.size() < s.size()) res += '0';
            reverse(res.begin(), res.end());
            while (res.size() <= 100) {
                res = 'F' + res;
                ans += mp[res];
            }
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}