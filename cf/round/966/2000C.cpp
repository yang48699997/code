#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m;
    cin >> m;
    vector<string> s(m);
    for (int i = 0; i < m; i++) cin >> s[i];

    vector<vector<int>> p(n);
    map<int, int> mp;
    for (int i = 0; i < n; i++) {
        if (mp.count(a[i])) {
            p[mp[a[i]]].push_back(i);
        } else {
            mp[a[i]] = i;
            p[i].push_back(i);
        }
    }
    for (int i = 0; i < m; i++) {
        string cur = s[i];
        if (cur.length() != n) {
            cout << "NO\n";
            continue;
        }
        int ok = 1;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int x = it->second;
            for (int j = 1; j < p[x].size(); j++) {
                if (cur[p[x][j]] != cur[p[x][0]]) ok = 0; 
            }
        }
        set<char> st;
        for (auto it = mp.begin(); it != mp.end(); it++) {
            int x = it->second;
            if (st.count(cur[x])) {
                ok = 0;
                break;
            }
            st.insert(cur[x]);
        }
        if (ok) {
            cout << "YES\n";
        } else cout << "NO\n";
    }
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