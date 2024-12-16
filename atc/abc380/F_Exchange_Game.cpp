#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, l;
    cin >> n >> m >> l;

    int N = n + m + l;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    vector<int> power(N + 1, 1);
    for (int i = 1; i <= N; i++) {
        power[i] = power[i - 1] * 3;
    }

    vector<vector<int>> sg(2, vector<int> (power[N], -1));

    auto dfs = [&](auto &&self, int x, int p) -> int {
        if (sg[p][x] != -1) return sg[p][x];

        for (int i = 0; i < N; i++) {
            if (x / power[i] % 3 != p) continue;
            
            if (!self(self, x - power[i] * p + power[i] * 2, p ^ 1)) {
                sg[p][x] = 1;
                return 1;
            }

            for (int j = 0; j < N; j++) {
                if (x / power[j] % 3 != 2) continue;

                if (a[j] >= a[i]) continue;
                if (!self(self, x - p * power[i] + 2 * power[i] - 2 * power[j] + p * power[j], p ^ 1)) {
                    sg[p][x] = 1;
                    return 1;
                }
            }
        }

        sg[p][x] = 0;
        return 0;
    };

    int now = 0;
    for (int i = n; i < n + m; i++) now += power[i];
    for (int i = n + m; i < n + m + l; i++) now += power[i] * 2;

    if (dfs(dfs, now, 0)) cout << "Takahashi\n";
    else cout << "Aoki\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}