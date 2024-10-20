#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> ans(n * 2 + 1);
    iota(ans.begin(), ans.end(), 0);
    int now = 1;
    for (int i = 1; now <= k; i++) {
        if (now % m == 0) swap(ans[i], ans[i + n]);
        now++;
        if (i == n) i = 0;
    }

    for (int i = 1; i <= 2 * n; i++) {
        cout << ans[i] << " \n"[i == 2 * n];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}