#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 32;
const int M = N * (N - 1) / 2;

ll dp[N][N][N][2][M];
ll c[N][N];
ll f[N][N][M];

void solve() {
    int n, p;
    cin >> n >> p;

    c[0][0] = 1;
    for (int i = 1; i < N; i++) {
        c[i][0] = 1;
        for (int j = 1; j <= i; j++) {
            c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % p;
        }
    }

    for (int i = 1; i < N / 2; i++) {
        f[i][0][0] = 1;
        for (int j = 1; j < N / 2; j++) {
            for (int k = 0; k < M; k++) {
                if (!f[i][j - 1][k]) continue;
                for (int l = 1; l <= i; l++) {
                    for (int h = 0; h < j; h++) {
                        f[i][j][k + l + h] = (f[i][j - 1][k] * c[i][l] % p * c[j - 1][h] + f[i][j][k + l + h]) % p;
                    }
                }
            }
        }
    }

    dp[1][0][1][0][0] = 1;
    vector<ll> ans(M);
    for (int l = 1; l <= n / 2; l++) {
        for (int r = 0; r <= n / 2; r++) {
            for (int u = 1; u <= n / 2; u++) {
                for (int op = 0; op <= 1; op++) {
                    for (int m = 0; m <= n * (n - 1) / 2; m++) {
                        if (!dp[l][r][u][op][m]) continue;

                        for (int v = 1; v <= n / 2; v++) {
                            int nl = l;
                            int nr = r;
                            if (op) nl += v;
                            else nr += v;

                            if (max(nl, nr) > n / 2) continue; 

                            for (int k = v; k <= v * u + v * (v - 1) / 2; k++) {
                                dp[nl][nr][v][op ^ 1][m + k] = (dp[nl][nr][v][op ^ 1][m + k] + dp[l][r][u][op][m] * f[u][v][k] % p * c[n - l - r][v]) % p;
                            }
                        }

                        if (l == r && l == n / 2) {
                            ans[m] = (ans[m] + dp[l][r][u][op][m]) % p;
                        }
                    }
                }
            }
        }
    }

    for (int i = n - 1; i <= (n - 1) * n / 2; i++) {
        cout << ans[i] << " \n"[i == (n - 1) * n / 2];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}