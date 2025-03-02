#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m;
    cin >> n >> m;

    vector<vector<int>> p(n, vector<int> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> p[i][j];
        }
        sort(p[i].begin(), p[i].end());
    }
    
    vector<int> a(n);
    iota(a.begin(), a.end(), 0);

    sort(a.begin(), a.end(), [&](int x1, int x2) {
        for (int i = 0; i < m; i++) {
            if (p[x1][i] != p[x2][i]) return p[x1][i] < p[x2][i]; 
        }
        return true;
    });

    int top = -1;
    for (int i = 0; i < m; i++) {
        for (int x : a) {
            if (p[x][i] <= top) {
                cout << "-1\n";
                return;
            }
            top = p[x][i];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] + 1 << " \n"[i == n - 1];
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) {
        solve();
    }
    return 0;
}