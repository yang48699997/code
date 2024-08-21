#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll inf = 1e18;
int T;
void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> dp(k + 1, inf);
    dp[0] = 0;
    vector<ll> c(4);
    for (int i = 0; i < n; i++) {
        for (int i = 0; i < 4; i++) {
            cin >> c[i];
        }
        for (int j = k; j >= 0; j--) {
            for (int p = 1; p <= 4; p++) {
                if (j - p < 0) continue;
                dp[j] = min(dp[j], dp[j - p] + c[p - 1]);
            }
        } 
    }
    cout << dp[k] << "\n";
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