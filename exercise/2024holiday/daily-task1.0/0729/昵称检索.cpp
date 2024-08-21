#include <bits/stdc++.h>
using namespace std;

int m[12] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
int d[12] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int T;

string to(int x) {
    string res;
    if (x < 10) res += '0';
    res += to_string(x);
    return res; 
}
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    vector<string> f(n);
    for (int i = 0; i < n; i++) cin >> f[i];
    vector<vector<int>> pos(36);
    for (int i = 0; i < m; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
            pos[s[i] - 'a'].push_back(i);
        } else {
            pos[s[i] - '0' + 26].push_back(i);
        }
    }
    set<string> st;
    for (int i = 0; i <12; i++) {
        string cur;
        cur = to(i + 1);
        for (int j = 0; j < d[i]; j++) {
            st.insert(cur + to(j + 1));
        }
    }
    int ans = 0;
    auto dfs = [&](auto &&self, string &p, int i, int j) -> int {
        if (i == p.length()) return j;
        char c = p[i];
        int tar = 0;
        if (c >= 'a' && c <= 'z') {
            tar = c - 'a';
        } else {
            tar = c - '0' + 26;
        }
        auto it = upper_bound(pos[tar].begin(), pos[tar].end(), j);
        if (it == pos[tar].end()) return 0;
        int now = pos[tar][it - pos[tar].begin()];
        return self(self, p, i + 1, now);
    };
    vector<int> dp(m + 1);
    for (int i = m - 1; i >= 0; i--) {
        dp[i] = dp[i + 1];
        if (s[i] >= 'a' && s[i] <= 'z') continue;
        auto it = st.begin();
        while (it != st.end()) {
            string str = *it;
            if (str[0] < s[i]) {
                it++;
                continue;
            }
            else if (str[0] > s[i]) break;
            int res = dfs(dfs, str, 0, i - 1);
            if (res == 0) it++;
            else dp[i]++, it = st.erase(it);
        }
    }
    for (int i = 0; i < n; i++) {
        int res = dfs(dfs, f[i], 0, -1);
        if (res == 0) continue;
        ans += dp[res + 1];
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