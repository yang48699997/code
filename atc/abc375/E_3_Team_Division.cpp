#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int inf = 1e9;
const int N = 500;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> dp(N + 1, vector<int> (N + 1, inf));
    dp[0][0] = 0;

    int sum = 0;
    while (n--) {
        int a, x;
        cin >> a >> x;
        sum += x;

        for (int i = N; i >= 0; i--) {
            for (int j = N; j >= 0; j--) {
                if (a == 1) {
                    if (i >= x) {
                        dp[i][j] = min(dp[i][j] + 1, dp[i - x][j]);
                    } else {
                        dp[i][j]++;
                    }
                    if (j >= x) dp[i][j] = min(dp[i][j], dp[i][j - x] + 1);
                } else if (a == 2) {
                    if (j >= x) {
                        dp[i][j] = min(dp[i][j] + 1, dp[i][j - x]);
                    } else {
                        dp[i][j]++;
                    }
                    if (i >= x) dp[i][j] = min(dp[i][j], dp[i - x][j] + 1);
                } else {
                    if (i >= x) dp[i][j] = min(dp[i][j], dp[i - x][j] + 1);
                    if (j >= x) dp[i][j] = min(dp[i][j], dp[i][j - x] + 1);
                }
            }
        }
    }   

    if (sum % 3 || dp[sum / 3][sum / 3] >= inf) {
        cout << "-1\n";
    } else {
        cout << dp[sum / 3][sum / 3] << "\n";
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}