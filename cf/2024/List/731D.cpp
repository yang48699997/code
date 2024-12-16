#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, c;
    cin >> n >> c;

    vector<int> pre(c + 1);

    vector<vector<int>> e(n);
    for (int i = 0; i < n; i++) {
        int m;
        cin >> m;
        for (int j = 0; j < m; j++) {
            int a;
            cin >> a;
            e[i].push_back(a);
        }
    }

    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            if (e[i + 1].size() == j) {
                cout << "-1\n";
                return;
            } else if (e[i + 1][j] == e[i][j]) continue;
            else {
                cnt++;
                int x = e[i][j];
                int y = e[i + 1][j];
                // cerr << x << ' ' << y << ":\n";
                if (x < y) {
                    pre[0]++;
                    pre[c - y + 1]--;
                    pre[c - x + 1]++;
                    pre[c]--;
                    // cerr << 0 << " " << c - y + 1 << " " << c - x + 1 << " " << c << "\n";
                } else {
                    pre[c - x + 1]++;
                    pre[c - y + 1]--;
                    // cerr << c - x + 1 << " " << c - y + 1 << "\n";
                }
                break;
            }
        }
    }

    if (pre[0] == cnt) {
        cout << 0 << "\n";
        return;
    } else {
        for (int i = 1; i < c; i++) {
            pre[i] += pre[i - 1];
            if (pre[i] == cnt) {
                cout << i << "\n";
                return;
            }
        }
    }
    cout << -1 << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}