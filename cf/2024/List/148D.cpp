#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b;
    cin >> b >> a;

    vector<vector<double>> dp(a + 1, vector<double> (b + 1));
    for (int i = 1; i <= b; i++) dp[0][i] = 1;
    for (int i = 1; i <= a; i++) {
        for (int j = 1; j <= b; j++) {
            double p1 = 1.0 * j / (i + j);
            double p2 = 1.0 * i / (i + j);
            dp[i][j] += p1;
            p2 *= 1.0 * (i - 1) / (i + j - 1);
            if (i + j <= 3) continue;
            if (i > 2) {
                double p3 = 1.0 * (i - 2) / (i + j - 2);
                dp[i][j] += p2 * p3 * dp[i - 3][j];
            } 
            if (j > 1 && i > 1) {
                double p4 = 1.0 * j / (i + j - 2);
                dp[i][j] += p2 * p4 * dp[i - 2][j - 1];
            }
        }
    }
    cout << fixed << setprecision(9) << dp[a][b] << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}