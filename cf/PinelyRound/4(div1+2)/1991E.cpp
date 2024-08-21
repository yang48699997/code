#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> c(n, -1);
    vector<vector<int>> e(n);
    int ok = 1;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    auto dfs = [&](auto &&self, int x, int p) -> void {
        c[x] = p;
        for (int nxt : e[x]) {
            if (c[nxt] != -1) {
                if (c[nxt] == p) ok = 0;
                continue;
            } 
            self(self, nxt, p ^ 1);
        }
    };
    dfs(dfs, 0, 0);
    vector<int> c1, c2;
    for (int i = 0; i < n; i++) {
        if (c[i] == 0) c1.push_back(i + 1);
        else c2.push_back(i + 1);
    }
    int l1 = 0, l2 = 0;
    if (ok) {
        cout << "Bob" << endl;
        for (int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            if (a > b) swap(a, b);
            if (a == 1) {
                if (l1 < c1.size()) {
                    cout << c1[l1++] << " " << a << endl;
                } else {
                    cout << c2[l2++] << " " << b << endl;
                }
            } else {
                if (l2 < c2.size()) {
                    cout << c2[l2++] << " " << a << endl;
                } else cout << c1[l1++] << " " << b << endl;
            }
        }
    } else {
        cout << "Alice" << endl;
        for (int i = 0; i < n; i++) {
            cout << 1 << " " << 2 << endl;
            int j, k;
            cin >> j >> k;
        }
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