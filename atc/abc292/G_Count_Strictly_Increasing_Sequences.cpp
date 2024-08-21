#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int mod = 998244353;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<vector<ll>>> dp(m + 1, vector<vector<ll>> (n, vector<ll> (n + 1)));
    for (int i = 0; i < n; i++) dp[m][i][i + 1] = 1;
    for (int i = m - 1; i >= 0; i--) {
        for (int l = 0; l < n; l++) {
            dp[i][l][l] = 1;
            for (int x = 0; x < 10; x++) {
                for (int L = n - 1; L >= l; L--) {
                    for (int R = L + 1; R <= n; R++) {
                        if (s[R - 1][i] != '?' && s[R - 1][i] != '0' + x) break;
                        dp[i][l][R] += dp[i][l][L] * dp[i + 1][L][R] %mod;
                        dp[i][l][R] %= mod;
                    }
                }
            }
        }
    }
    cout << dp[0][0][n] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}