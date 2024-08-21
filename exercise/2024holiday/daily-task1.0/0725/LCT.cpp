#include <bits/stdc++.h>
using namespace std;


struct DSU{
    vector<int> fa;
    DSU(int n):fa(n){
        for(int i=0;i<n;i++)fa[i]=i;
    }
    int find(int x){
        if(fa[x]==x)return x;
        fa[x]=find(fa[x]);
        return fa[x];
    }
    bool merge(int x,int y){
        x=find(x);
        y=find(y);
        if(x==y)return false;
        fa[y]=x;
        return true;
    }
};

int T;
void solve() {
    int n;
    cin >> n;
    vector<int> mx(n);
    vector<pair<int, int>> p(n - 1);
    vector<int> qq(n);
    vector<vector<int>> e(n);
    vector<int> fa(n, -1);
    for (int i = 0; i < n - 1; i++) {
        int x, y, c;
        cin >> x >> y >> c;
        x--;
        y--;
        c--;
        p[i] = make_pair(x, y);
        qq[i] = c;
        e[x].push_back(y);
        e[y].push_back(x);
        fa[y] = x;
    }
    vector<int> d(n);
    int r = 0;
    for (int i = 0; i < n; i++) {
        if (fa[i] == -1) {
            r = i;
            break;
        }
    }
    queue<int> q;
    q.push(r);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int nxt : e[x]) {
            if (nxt == fa[x]) continue;
            d[nxt] = d[x] + 1;
            q.push(nxt);
        }
    }
    DSU dsu(n);
    for (int i = 0; i < n - 1; i++) {
        auto [x, y] = p[i];
        int c = qq[i];
        y = dsu.find(y);
        int p = mx[y];
        int f = dsu.find(x);
        p += d[x] - d[f] + 1;
        mx[f] = max(mx[f], p);
        dsu.merge(f, y);
        cout << mx[dsu.find(c)] << " \n"[i == n - 2];  
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