#include <bits/stdc++.h>
using namespace std;

int T;
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> e(n + 1);
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<int> f(n + 1, 1);
    vector<int> sz(n + 1, 1);
    
    auto dfs = [&](auto &&self,int x, int fa) -> void {
        f[x] = fa;
        for (int nxt : e[x]) {
            if (nxt == fa) continue;
            self(self, nxt, x);
            sz[x] += sz[nxt];
        }
    };

    int res = 0;
    int ans = 1;
    while (!res) {

    }
    cout << 
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