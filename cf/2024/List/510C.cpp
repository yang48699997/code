#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(26);
    vector<int> deg(26);
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i]; 

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int m = min(s[i].length(), s[j].length());
            if (s[i].substr(0, m) == s[j].substr(0, m) && s[i].length() > s[j].length()) {
                cout << "Impossible\n";
                return;
            }
            for (int k = 0; k < m; k++) {
                if (s[i][k] == s[j][k]) continue;
                deg[s[j][k] - 'a']++;
                e[s[i][k] - 'a'].push_back(s[j][k] - 'a');
                break;
            }
        }
    }

    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (deg[i] == 0) q.push(i);
    }
    string ans;
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        ans += (char)('a' + x);
        for (int nxt : e[x]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.push(nxt);
            }
        }
    }

    if (ans.size() == 26) cout << ans << "\n";
    else cout << "Impossible\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}