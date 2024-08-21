#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int dp1 = 0, dp2 = 0, dp3 = 0;
    const int inf = 1e9;
    for (int i = 0; i < n; i++) {
        int t1 = dp1;
        int t2 = dp2;
        int t3 = dp3;
        if (s[i] == 'R') {
            dp1 = max(t2, t3);
            dp2 = -inf;
            dp3 = max(t1, t2) + 1;
        } else if (s[i] == 'S') {
            dp1 = max(t2, t3) + 1;
            dp2 = max(t1, t3);
            dp3 = -inf;
        } else {
            dp1 = -inf;
            dp2 = max(t1, t3) + 1;
            dp3 = max(t1, t2);
        }
        // cerr << dp1 << " " << dp2 << " " << dp3 << "\n";
    }


    cout << max({dp1, dp2, dp3}) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}