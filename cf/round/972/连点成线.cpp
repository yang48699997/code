#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> r(n), c(n);
    while (m--) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        r[x].push_back(y);
        c[y].push_back(x);
    } 
    
    int ans = 0;
    for (int i = 0; i < n; i++) {
        sort(r[i].begin(), r[i].end());
        sort(c[i].begin(), c[i].end());
        if (r[i].size()) ans = max(ans, r[i].back() - r[i][0]);
        if (c[i].size()) ans = max(ans, c[i].back() - c[i][0]);
    }
    cout << ans << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}