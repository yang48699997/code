#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> pre[i];
        pre[i] += pre[i - 1];
    }

    int ans = pre[n];
    int mx = ans;
    for (int i = n - 1; i > 1; i--) {
        int now = pre[i] - mx;
        ans = max(ans, now);
        mx = max(mx, now);
    }

    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}