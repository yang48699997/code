#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        deg[x]++;
        deg[y]++;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (deg[i] > 1) cnt++;
    }
    for (int i = 0; i < n; i++) {
        if (deg[i] != 2) continue;
        int c = 1;
        for (int nxt : e[i]) {
            if (deg[nxt] == 2) c++;
            if (cnt - c <= 1) {
                cout << "Yes\n";
                return;
            } else if (cnt - c == 2) {
                int ok = 1;
                for (int j = 0; j < 2; j++) {
                    if (deg[e[i][j]] > 2) continue;
                    if (deg[e[i][j]] == 1) ok = 0;
                    for (int np : e[e[i][j]]) {
                        if (np == i) continue;
                        if (deg[np] == 1) ok = 0;
                    }
                }
                if (ok) {
                    cout << "Yes\n";
                    return;
                }
            }
        }
    }

    cout << "No\n";
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