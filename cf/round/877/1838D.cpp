#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;

    if (n & 1) {
        while (q--) {
            int x;
            cin >> x;
            cout << "NO\n";
        }
        return;
    }

    vector<set<int>> st(4);
    map<string, int> mp = {{"()", 0}, {"((", 1}, {"))", 2}, {")(", 3}};
    for (int i = 0; i < n; i += 2) {
        st[mp[s.substr(i, 2)]].insert(i);
    }

    while (q--) {
        int x;
        cin >> x;
        x--;
        st[mp[s.substr(x - x % 2, 2)]].erase(x - x % 2);
        if (s[x] == '(') s[x] = ')';
        else s[x] = '(';
        st[mp[s.substr(x - x % 2, 2)]].insert(x - x % 2);
        int ok = 0;
        if (st[1].empty()) {
            if (st[2].empty() && st[3].empty()) ok = 1;
        } else {
            if (!st[2].empty()) {
                if (st[3].empty()) {
                    if (*st[1].begin() < *st[2].begin() && *st[1].rbegin() < *st[2].rbegin()) ok = 1;
                } else if (*st[1].begin() < *st[2].begin() && *st[1].rbegin() < *st[2].rbegin() && *st[1].begin() < *st[3].begin() && *st[2].rbegin() > *st[3].rbegin()) ok = 1;
            }
        }
        if (ok) cout << "YES\n";
        else cout << "NO\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}