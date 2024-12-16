#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;

void solve() {
    int n, q;
    cin >> n >> q;

    vector<int> dp(n, inf);
    char pc = 'L';
    int pre = 0;
    dp[1] = 0;

    while (q--) {
        char c;
        int t;
        cin >> c >> t;
        t--;

        vector<int> ndp(n, inf);
        auto work = [&](int l, int r, int t, int cost) -> void {
            if (l == r) return;
            
            int d1 = (t + n - l) % n;
            int d2 = (t + n - r) % n;
            if (d1 < d2) {
                ndp[r] = min(ndp[r], cost + d1);
            } else {
                ndp[(t + 1) % n] = min(ndp[(t + 1) % n], cost + d1 + d2 + 1);
            }

            d1 = (l + n - t) % n;
            d2 = (r + n - t) % n;
            if (d1 < d2) {
                ndp[r] = min(ndp[r], cost + d1);
            } else {
                ndp[(t - 1 + n) % n] = min(ndp[(t - 1 + n) % n], cost + d1 + d2 + 1);
            }
        };

        if (c == pc) {
            for (int i = 0; i < n; i++) {
                work(pre, i, t, dp[i]);
            }     
        } else {
            for (int i = 0; i < n; i++) {
                work(i, pre, t, dp[i]);
            } 
        }

        dp = ndp;
        pc = c;
        pre = t;

    }

    cout << *min_element(dp.begin(), dp.end()) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}