#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> g(n + 1, vector<int> (n + 1));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cin >> g[i][j];
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) {
        if (ans < i) ans = g[i][ans];
        else ans = g[ans][i];
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}