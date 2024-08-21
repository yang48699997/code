#include <bits/stdc++.h>
using namespace std;

struct DSU{
    vector<int> fa,size;
    DSU(int n):fa(n),size(n,1){
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
        size[x]+=size[y];
        fa[y]=x;
        return true;
    }
    int getcount(int x){
        x=find(x);
        return size[x];
    }
};

const int N=1e5+5;
vector<int> e[N];
int dfn[N],low[N];
int stk[N],instk[N];
int scc[N],siz[N], v[N << 1];
int adj[N << 1];
int tot,top,cnt;
int n,m;

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk[top++]=x;
    instk[x]=1;
    for(int nxt:e[x]){
        if (v[nxt]) continue;
        v[nxt] = 1;
        nxt = x ^ adj[nxt];
        if(!dfn[nxt])tarjan(nxt),low[x]=min(low[x],low[nxt]);
        else if(instk[nxt])low[x]=min(low[x],dfn[nxt]);
    }
    if(dfn[x]==low[x]){
        cnt++;
        int y=0;
        while(y!=x){
            y=stk[--top];
            instk[y]=0;
            scc[y]=cnt;
            siz[cnt]++;
        }
    }
}


void solve() {
    int n, m;
    cin >> n >> m;
    
    for(int i=1;i<=n;i++)dfn[i]=low[i]=instk[i]=siz[i]=0,e[i].clear();
    for (int i = 0; i < m; i++) v[i] = 0;
    top=tot=cnt=0;
    vector<pair<int, int>> p;
    vector<int> ok(m);
    for (int i = 0; i < m; i++) {
        int x,y;
        cin>>x>>y;
        string s;
        cin >> s;
        p.emplace_back(x, y);
        adj[i] = (x ^ y);
        if (s == "Lun") {
            e[x].push_back(i);
            e[y].push_back(i);
            ok[i] = 1;
        } 
    }
    for (int i = 1; i <= n; i++) {
        if (!dfn[i]) tarjan(i);
    }
    DSU dsu(n + 1);
    vector<pair<int, int>> ans;
    for (int i = 0; i < m; i++) {
        if (!ok[i]) continue;
        int x = p[i].first;
        int y = p[i].second;
        if (scc[x] == scc[y]) {
            ans.emplace_back(x, y);
            dsu.merge(x, y);
        }
    }
    for (int i = 0; i < m; i++) {
        if (ok[i]) continue;
        int x = p[i].first;
        int y = p[i].second;
        if (dsu.find(x) != dsu.find(y)) {
            ans.emplace_back(x, y);
            dsu.merge(x, y);
        }
    }

    if (dsu.getcount(1) != n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
        cout << ans.size() << "\n";
        for (auto [x, y] : ans) {
            cout << x << " " << y << "\n";
        }
    }
}   

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}