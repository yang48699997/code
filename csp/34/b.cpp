#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, t;
    cin >> n >> m >> t;
    vector<int> a(n * m);
    for (int i = 0; i < n * m; i++) {
        cin >> a[i];
    }
    int rev = 0;
    while (t--) {
        int c, i, j;
        cin >> c >> i >> j;
        if (c == 1) {
            n = i;
            m = j;
        } else if (c == 2) {
            vector<int> tmp = a;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    a[i * n + j] = tmp[j * m + i];
                }
            }
            swap(n, m);
        } else {
            cout << a[i * m + j] << "\n";
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}