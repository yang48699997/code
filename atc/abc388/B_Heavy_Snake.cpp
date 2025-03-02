#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, d;
    cin >> n >> d;

    vector<int> t(n), l(n);
    vector<int> ans(d);
    for (int i = 0; i < n; i++) {
        cin >> t[i] >> l[i];
        for (int j = 0; j < d; j++) {
            ans[j] = max(ans[j], t[i] * (l[i] + j + 1));
        }
    }

    for (int i = 0; i < d; i++) {
        cout << ans[i] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}