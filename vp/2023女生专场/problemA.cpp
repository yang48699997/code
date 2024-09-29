#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    vector<vector<int>> p(10);
    p[2].push_back(1);
    p[3].push_back(2);
    p[4].push_back(3);
    vector<int> pos{0, 2, 3, 4};
    for (int i = 0; i < 12; i++) {
        int c, x;
        cin >> c >> x;
        int now = pos[c];
        int t = 0;
        for (int j = 0; j < p[now].size(); j++) {
            if (p[now][j] == c) {
                t = j;
                break;
            }
        }
        for (int j = t; j < p[now].size(); j++) {
            pos[p[now][j]] = now + x;
            p[now + x].push_back(p[now][j]);
        }
        t = p[now].size() - t;
        while (t--) p[now].pop_back();
    }
    int ok = (p[9].size() == 3);
    if (ok) cout << "Y\n";
    else cout << "N\n";
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