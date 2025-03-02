#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> c(n, vector<int> (m));
    vector<int> cnt(n * m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c[i][j];
            c[i][j]--;
            
            if (!cnt[c[i][j]]) cnt[c[i][j]] = 1;
            if (i > 0 && c[i][j] == c[i - 1][j]) cnt[c[i][j]] = 2;
            if (j > 0 && c[i][j] == c[i][j - 1]) cnt[c[i][j]] = 2;
        }
    }

    sort(cnt.begin(), cnt.end());

    cout << accumulate(cnt.begin(), cnt.end(), 0) - cnt.back() << '\n';
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