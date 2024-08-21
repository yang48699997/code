#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    map<string, string> mp;
    for (int i = 0; i < n; i++) {
        string s1, s2;
        cin >> s1 >> s2;
        mp[s2] = s1;
    }

    while (q--) {
        string s;
        cin >> s;
        s += '.';
        vector<string> p;
        int pre = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] != '.') continue;
            p.push_back(s.substr(pre, i - pre));
            pre = i + 1;
        }
        string cur = mp[p[0]];
        int l = 0, r = cur.length() - 1;
        for (int i = 1; i < p.size(); i++) {
            if (p[i] == "first") {

            } else {

            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}