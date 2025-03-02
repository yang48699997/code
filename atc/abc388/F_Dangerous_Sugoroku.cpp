#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int N = 22;

void solve() {
    ll n;
    int m, a, b;
    cin >> n >> m >> a >> b;

    vector<ll> l(m + 2, n + 1), r(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> l[i] >> r[i];
    }

    vector<vector<int>> v(m + 1, vector<int> (N));
    v[0][1] = 1;

    vector<int> can(N * N);
    can[0] = 1;
    for (int i = 1; i < N * N; i++) {
        for (int j = a; j <= b; j++) {
            if (i - j < 0) break;
            can[i] |= can[i - j];
        }
    }

    auto check = [&](ll x, int k) -> int {
        int ok = 0;

        for (int i = 1; i < N; i++) {
            if (!v[k][i]) continue;
            if (x < i) continue;

            ll d = x - i;

            if (a == b) {
                if (d % a == 0) return 1;
                continue;
            }

            if (d >= N * N) return 1;
            
            ok |= can[d];
        }

        return ok;
    };
    
    for (int i = 1; i <= m; i++) {
        for (int p = 1; p <= min(N, i); p++) {
            ll d = min(1LL * N, l[i + 1] - r[i]);
            for (int j = 1; j < d; j++) {
                for (int k = a; k <= b; k++) {
                    if (r[i] + j - k >= l[i - p + 1]) continue;
                    v[i][j] |= check(r[i] + j - k - r[i - p], i - p);
                }
            }
        }
    }

    cout << (check(n - r[m], m) ? "Yes" : "No") << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}