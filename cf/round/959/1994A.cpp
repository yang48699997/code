#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    if (n == 1 && m == 1) {
        cout << "-1\n";
        return;
    }
    if (m == 1) {
        for (int i = 1; i < n; i++) cout << a[i][0] << "\n";
        cout << a[0][0] << "\n";
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 1; j < m; j++) cout << a[i][j] << " ";
        cout << a[i][0] << "\n";
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}