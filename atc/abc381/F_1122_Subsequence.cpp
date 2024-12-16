#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 20;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<vector<int>> nxt(N, vector<int> (n + 2, n + 1)); 
    for (int i = n - 1; i >= 0; i--) {
        for (int j = 0; j < N; j++) {
            nxt[j][i + 1] = nxt[j][0];
        }
        nxt[a[i] - 1][0] = i + 1;
    }

    int ans = 0;
    vector<int> dp(1 << N, n + 1);
    dp[0] = 0;

    for (int i = 0; i < 1 << N; i++) {
        for (int j = 0; j < N; j++) {
            if (1 << j & i) continue;   
            dp[i | (1 << j)] = min(dp[i | (1 << j)], nxt[j][nxt[j][dp[i]]]);
        }
        if (dp[i] != n + 1) {
            ans = max(ans, 2 * __builtin_popcount(i));
        }
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}