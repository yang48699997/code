#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int q(int a, int b) {
    cout << "? " << a << " " << b << endl;
    int ans;
    cin >> ans;
    return ans;
}


void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    vector<int> v(n + 1);
    v[1] = 1;

    auto dfs = [&](auto &&self, int x, int y) -> void {
        int res = q(x, y);
        if (res == x) {
            v[x] = v[y] = 1; 
            e[x].push_back(y);
            return;
        }
        if (!v[res]) self(self, x, res);
        self(self, res, y);
    };

    for (int i = 2; i <= n; i++) {
        if (!v[i]) {
            dfs(dfs, 1, i);
        }
    }
    cout << "!" << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < e[i].size(); j++) {
            cout << i << " " << e[i][j] << endl;
        }
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