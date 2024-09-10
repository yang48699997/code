#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> v(26);
    vector<string> s(n);
    vector<vector<string>> p(n);
    vector<int> f(n);
    string index = "";
    for (int i = 0; i < n; i++) {
        cin >> s[i] >> f[i];
        for (char c : s[i]) {
            v[c - 'a']++;
            p[i].push_back(index + c);
            cerr << p[i].back();
        }
    }
    vector<string> ans;
    for (int i = 0; i < 26; i++) {
        if (v[i]) ans.push_back(index + (char)('a' + i));
    }

    while (ans.size() < m) {
        map<pair<string, string>, ll> cnt;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < p[i].size() - 1; j++) {
                cnt[make_pair(p[i][j], p[i][j + 1])] += f[i];
            }
        }
        pair<string, string> res = cnt.begin() -> first;
        ll c = cnt.begin() -> second;
        auto it = cnt.begin();
        while (it != cnt.end()) {
            if (it -> second > c) {
                c = it -> second;
                res = it -> first;
            } else if (it -> second == c) {
                int l1 = it -> first.first.size();
                int l2 = it -> first.second.size();
                if (l1 + l2 < res.first.size() + res.second.size()) {
                    res = it -> first;
                } else if (l1 + l2 == res.first.size() + res.second.size()) {
                    if (l1 < res.first.size()) {
                        res = it -> first;
                    } else if (l1 == res.first.size()) {
                        if (it -> first.first + it -> first.second < res.first + res.second) {
                            res = it -> first;
                        }
                    }
                }
            }
            it++;
        }
        ans.push_back(res.first + res.second);
        for (int i = 0; i < n; i++) {
            vector<string> nxt;
            for (int j = 0; j < p[i].size(); j++) {
                if (j > 0 && p[i][j] == res.second && nxt.back() == res.first) {
                    nxt.back() += p[i][j];
                } else nxt.push_back(p[i][j]);
            }
            p[i] = nxt;
        }
    }

    for (int i = 0; i < m; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}