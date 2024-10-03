#include <bits/stdc++.h>

using namespace std;
struct DSU{
    vector<int> fa, sz;
    
    DSU(int n) : fa(n), sz(n, 1) {
        for ( int i = 0; i < n; i++) fa[i]=i;
    }

    int find(int x) {
        if (fa[x] == x) return x;
        fa[x] = find(fa[x]);
        return fa[x];
    }

    bool merge(int x, int y) {
        x = find(x);
        y = find(y);
        if( x == y) return false;
        sz[x] += sz[y];
        fa[y] = x;
        return true;
    }
    
    int size(int x) {
        x = find(x);
        return sz[x];
    }
};

void solve(){
    int n, m;
    cin >> n >> m;
    vector<vector<int>> e1(n + 1), e2(n + 1);
    vector<int> in1(n + 1), in2(n + 1);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        e1[x].push_back(y);
        in1[y]++;
        e2[y].push_back(x);
        in2[x]++;
    }
    DSU dsu1(n + 1), dsu2(n + 1);
    vector<int> big(n + 1), small(n + 1);

    queue<int> q;   
    for (int i = 1; i <= n; i++) {
        if (!in1[i]) {
            big[i] = dsu1.size(i) - 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int cur = q.front();
        q.pop();
        for (auto j : e1[cur]) {
            in1[j]--;
            dsu1.merge(cur, j);
            if (!in1[j]) {
                big[j] = dsu1.size(j) - 1;
                q.push(j); 
            }
        }
    }

    for (int i = 1; i <= n; i++) {
        if (in1[i]) { 
            string s = string(n, '0');
            cout << s << endl;
            return;
        }
    }

    queue<int> qq;
    for (int i = 1; i <= n; i++) {
        if (!in2[i]) {
            qq.push(i);
        }
    }
    while (!qq.empty()) {
        int cur = qq.front();
        qq.pop();
        for (auto j : e2[cur]) {
            in2[j]--;
            dsu2.merge(j, cur);
            if (!in2[j]) {
                small[j] = dsu2.size(j) - 1;
                qq.push(j); 
            }
        }
    }
    int c = n / 2;
    vector<int> can(n + 1);
    for (int i = 1; i <= n; i++) {
        if (small[i] <= c && big[i] <= c) {
            can[i] = 1;
        }
    }
    string s = string(n, '0');
    for (int i = 1; i <= n; i++) {
        if (can[i]) s[i - 1] = '1';
    }
    cout << s << endl;
}
signed main(){
    ios::sync_with_stdio(false); 
    cin.tie(0);
    int t;
    cin >> t;
    while (t--) {
       solve();
    }
    return 0;
}