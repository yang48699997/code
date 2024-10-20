#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, x, y;
    cin >> n >> x >> y;
    cout << "Yes\n";
    vector<vector<int>> g(n + 1, vector<int> (n + 1));
    g[x][y] = 1;
    int l = y, r = y;
    int u = x, d = x; 
    for (int i = 1; i < n; i++) {
        if (d < n && r < n) {
            cout << i << " " << d + 1 << " " << l << " " << 1 << "\n";
            cout << i + 1 << " " << u << " " << r + 1 << " " << 0 << "\n";
            d++;
            r++;
        } else if (d < n && l > 1) {
            cout << i << " " << d + 1 << " " << l << " " << 1 << "\n";
            cout << i + 1 << " " << u << " " << l - 1 << " " << 0 << "\n";
            d++;
            l--;
        } else if (u > 1 && r < n) {
            cout << i << " " << u - 1 << " " << l << " " << 1 << "\n";
            cout << i + 1 << " " << u - 1 << " " << r + 1 << " " << 0 << "\n";
            u--;
            r++;
        } else {
            cout << i << " " << u - 1 << " " << l << " " << 1 << "\n";
            cout << i + 1 << " " << u - 1 << " " << l - 1 << " " << 0 << "\n";
            u--;
            l--;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}