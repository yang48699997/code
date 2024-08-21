#include <bits/stdc++.h>
using namespace std;

int to_int(string &s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        res = res * 2 + s[i] - '0';
    }
    return res;
}
int T;
void solve() {
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int p = to_int(s);
    const int inf = 1e9;
    vector<vector<int>> adj(1 << n, vector<int> (1 << n, inf));
    vector<int> dis(1 << n, inf), v(1 << n);
    while (m--) {
        int d;
        cin >> d;
        string str1, str2;
        cin >> str1 >> str2;
        int rem = to_int(str1);
        int cas = to_int(str2);
        for (int i = 0; i < 1 << n; i++) {
            int cur = i;
            for (int j = 0; j < n; j++) {
                if ((1 << j & cur) && (1 << j & rem)) cur ^= 1 << j;
            }
            cur |= cas;
            adj[i][cur] = min(adj[i][cur], d);
        }
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> q;
    q.push({0, p});
    dis[p] = 0;
    while (!q.empty()) {
        auto [x, u] = q.top();
        q.pop();
        if (v[u]) continue;
        if (u == 0) break;
        v[u] = 1;
        for (int i = 0; i < 1 << n; i++) {
            if (v[i] || adj[u][i] + dis[u] >= dis[i]) continue;
            dis[i] = adj[u][i] + dis[u];
            q.push({dis[i], i});
        }
    }
    cout << (dis[0] == inf ? -1 : dis[0]) << "\n";
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