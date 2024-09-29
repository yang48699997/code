#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n;
    cin >> n;
    map<int, vector<int>> p;
    map<int, int> sg;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        int sq = sqrt(x);
        for (int j = 2; j * j <= x; j++) {
            if (x % j != 0) continue;
            int cnt = 0;
            while (x % j == 0) {
                cnt++;
                x /= j;
            }
            p[j].push_back(cnt);
        }
        if (x > 1) p[x].push_back(1);
    }
    int ans = 0;
    
    auto dfs = [&](auto &&self, int x) -> int {
        if (sg.count(x)) return sg[x];
        if (x == 0) return 0;
        vector<int> nxt;
        for (int i = 0; i < 30; i++) {
            if ((1 << i) <= x) {
                int now = (((1 << i) - 1) & x);
                now |= x >> i >> 1;
                nxt.push_back(self(self, now));
            }
        }
        sort(nxt.begin(), nxt.end());
        nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
        int res = nxt.size();
        for (int i = 0; i < nxt.size(); i++) {
            if (nxt[i] != i) {
                res = i;
                break;
            }
        }
        sg[x] = res;
        return res;
    };
    for (auto it : p) {
        int x = 0;
        for (auto i : it.second) {
            x |= (1 << (i - 1));
        }
        ans ^= dfs(dfs, x);
    }
    if (ans) cout << "Mojtaba\n";
    else cout << "Arpa";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}