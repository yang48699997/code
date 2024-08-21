#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> p(k);
    for (int i = k - 1; i >= 0; i--) {
        char c;
        cin >> c;
        p[i] = c - '0';
    }
    vector<int> cnt(k);
    for (int i = 0; i < n; i++) {
        for (int j = k - 1; j >= 0; j--) {
            char c;
            cin >> c;
            cnt[j] += c - '0';
        }
    }

    vector<vector<int>> dp(k + 1, vector<int> (n + 1));
    vector<vector<tuple<int, int, int>>> pos(k + 1, vector<tuple<int, int, int>> (n + 1, make_tuple(0, 0, 0)));
    dp[0][0] = 1;
    for (int i = 0; i < k; i++) {
        for (int j = 0; j <= n; j++) {
            if (!dp[i][j]) continue;
            int d1 = j + cnt[i];
            int d2 = j + n - cnt[i];
            if (d1 & 1 ^ p[i]) ;
            else {
                dp[i + 1][d1 / 2] = 1;
                pos[i + 1][d1 / 2] = make_tuple(i, j, 0);
            }
            if (d2 & 1 ^ p[i]) ;
            else {
                dp[i + 1][d2 / 2] = 1;
                pos[i + 1][d2 / 2] = make_tuple(i, j, 1);
            }
        }
    }
    
    if (!dp[k][0]) {
        cout << "-1\n";
        return;
    }
    string ans;
    int x = k, y = 0;
    while (x || y) {
        ans += get<2>(pos[x][y]) + '0';
        int xx = get<0>(pos[x][y]);
        y = get<1>(pos[x][y]);
        x = xx;
    }
    // reverse(ans.begin(), ans.end());
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