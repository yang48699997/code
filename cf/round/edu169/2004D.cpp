#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;
void solve() {
    int n, q;
    cin >> n >> q;
    map<char, int> mp = {{'B', 0}, {'R', 1}, {'G', 2}, {'Y', 3}};
    vector<string> s(n);
    vector<vector<int>> e(40);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        e[mp[s[i][0]] * 10 + mp[s[i][1]]].push_back(i);
    }  

    while (q--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        if (s[x][0] == s[y][0] || s[x][0] == s[y][1] || s[x][1] == s[y][0] || s[x][1] == s[y][1]) {
            cout << abs(x - y) << "\n";
            continue;
        }
        if (x > y) swap(x, y);
        int ans = inf;
        int p1 = mp[s[x][0]] * 10 + mp[s[x][1]];
        int p2 = mp[s[y][0]] * 10 + mp[s[y][1]];
        for (int i = 0; i < 40; i++) {
            if (i == p1 || i == p2) continue;
            auto it = lower_bound(e[i].begin(), e[i].end(), x);
            if (it != e[i].end()) {
                ans = min(ans, abs(*it - x) + abs(*it - y));
            }
            if (it != e[i].begin()) {
                it--;
                ans = min(ans, abs(*it - x) + abs(*it - y));
            }
        }
        if (ans == inf) cout << "-1\n";
        else cout << ans << "\n";
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