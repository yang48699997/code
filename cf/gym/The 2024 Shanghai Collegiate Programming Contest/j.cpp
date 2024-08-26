#include <bits/stdc++.h>
using namespace std;

using ll = long long;

const int mx = 1e6 + 5;
int p[mx], v[mx];
int tot;

void solve() {
    int n;
    cin >> n;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }
    int ans = 1e9;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (v[pre[j] - pre[i]]) ans = min(ans, j - i - 1);
        }
    }
    if (ans == 1e9) ans = -1;
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    for (int i = 0; i < mx; i++) {
        p[i] = v[i] = 0;
    }
    tot = 0;
    for (int i = 2; i < mx; i++) {
        if (!v[i]) {
            p[tot++] = i;
        }
        for (int j = 0; i * p[j] < mx; j++) {
            v[i * p[j]] = 1;
            if (p[j] % i == 0) break;
        }
    }

    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}