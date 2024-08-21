#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> dp(k + 1, inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vector<int> p(x + y + 1, inf);
        p[0] = 0;
        int now = 0;
        int cnt = 0;
        while (x && y) {
            if (x > y) swap(x, y);
            cnt += x;
            if (y == 1) now++;
            y--;
            now++;
            p[now] = cnt;
        }    
        for (int j = k; j >= 0; j--) {
            for (int q = now; q > 0; q--) {
                int t = min(k, q + j);
                dp[t] = min(dp[t], dp[j] + p[q]);
            }
        }
    }
    cout << (dp[k] == inf ? -1 : dp[k]) << "\n";
    
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