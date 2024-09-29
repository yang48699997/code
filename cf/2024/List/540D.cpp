#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int a, b, c;
    cin >> a >> b >> c;

    auto cal = [](int a, int b, int c) -> double {
        vector<vector<vector<double>>> dp(a + 1, vector<vector<double>> (b + 1, vector<double> (c + 1)));
        for (int i = 1; i <= a; i++) {
            for (int j = 0; j <= b; j++) {
                dp[i][j][0] = 1;
            }
        }
        for (int k = 1; k <= c; k++) {
            for (int i = 1; i <= a; i++) {
                for (int j = 1; j <= b; j++) {
                    ll sum = i * j + i * k + j * k;
                    double p1 = 1.0 * i * j / sum;
                    double p2 = 1.0 * k * j / sum; 
                    double p3 = 1.0 * i * k / sum; 
                    dp[i][j][k] = dp[i][j - 1][k] * p1 + dp[i][j][k - 1] * p2 + dp[i - 1][j][k] * p3;
                }
            }
        }
        return dp[a][b][c];
    };

    cout << fixed << setprecision(12) << cal(a, b, c) << " " << cal(b, c, a) << " " << cal(c, a, b) << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}