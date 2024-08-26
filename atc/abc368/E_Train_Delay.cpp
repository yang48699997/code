#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void solve() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<ll> d(n);
    d[0] = k;
    vector<array<int, 4>> p;
    map<int, int> last;
    for (int i = 0; i < m; i++) {
        int a, b, s, t;
        cin >> a >> b >> s >> t;
        p.emplace_back(a, b, s, t);
        last[a] = max(last[a], s);
    }   
    // vector<int> nums(m);
    // iota(nums.begin(), nums.end(), 0);
    // sort(nums.begin(), nums.end(), [&](int x1, int x2) {
    //     return p[x1][2] < p[x2][2];
    // });
    vector<vector<int>> e(n);
    vector<int> deg(n);
    for (int i = 0; i < m; i++) {
        if (!last.count(p[i][1])) continue;
        if (last[p[i][1]] >= p[i][3]) {
            e[p[i][0]].push_back(p[i][1]);
            deg[p[i][1]]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++) {
        if (!deg[i]) q.push(i);
    }
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            deg[nxt]--;
            if (!deg[nxt]) q.push(nxt);
            d[nxt] = max(d[nxt], d[x] )
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}