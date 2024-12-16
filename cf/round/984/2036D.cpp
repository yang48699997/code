#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<string> g(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
    }

    int ans = 0;

    string s = "1543";

    for (int i = 0; i < min(n / 2, m / 2); i++) {
        vector<char> p;
        for (int j = i; j < m - i; j++) {
            p.push_back(g[i][j]);
        }
        for (int j = i + 1; j < n - i; j++) {
            p.push_back(g[j][m - i - 1]);
        }
        for (int j = m - i - 2; j >= i; j--) {
            p.push_back(g[n - i - 1][j]);
        }
        for (int j = n - i - 2; j > i; j--) {
            p.push_back(g[j][i]);
        }
        int sz = p.size();

        for (int j = 0; j < p.size(); j++) {
            if (p[j] == '1' && p[(j + 1) % sz] == '5' && p[(j + 2) % sz] == '4' && p[(j + 3) % sz] == '3') ans++;
        }
    }

    cout << ans << "\n";
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