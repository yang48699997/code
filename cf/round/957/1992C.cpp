#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m, k;
    cin >> n >> k >> m;
    vector<int> a(n);
    for (int i = n; i >= m; i--) cout << i << " ";
    for (int i = k + 1; i < m; i++) cout << i << " ";
    for (int i = 1; i <= k; i++) cout << i << " ";
    cout << "\n";
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