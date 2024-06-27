#include<bits/stdc++.h>

#define Rint register int
#define mem(a,b) memset(a,(b),sizeof(a))
#define Temp template<typename T>
using namespace std;
typedef long long LL;
Temp inline void read(T &x){
    x=0;T w=1,ch=getchar();
    while(!isdigit(ch)&&ch!='-')ch=getchar();
    if(ch=='-')w=-1,ch=getchar();
    while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
    x=x*w;
}

#define mid ((l+r)>>1)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define len (r-l+1)

const int maxn=2e5+5;
int n,m,r,mod,q;
int e, beg[maxn], nex[maxn], to[maxn], w[maxn], wt[maxn];
int a[maxn<<2], laz[maxn<<2];
int son[maxn], id[maxn], fa[maxn], cnt, dep[maxn], siz[maxn], top[maxn];
int res = 0;

inline void add(int x, int y){
    to[++e] = y;
    nex[e] = beg[x];
    beg[x] = e;
}

inline void build(int rt, int l, int r){
    if(l == r){
        a[rt] = wt[l];
        return;
    }
    build(lson);
    build(rson);
    a[rt] = a[rt<<1] + a[rt<<1|1];
}

inline void query(int rt, int l, int r, int L, int R){
    if(L <= l && r <= R){
        res += a[rt];
        return;
    }
    if(L <= mid) query(lson, L, R);
    if(R > mid) query(rson, L, R);
}

inline void update(int rt, int l, int r, int L, int R, int k){
    if(L <= l && r <= R){
        a[rt] += k * len;
        return;
    }
    if(L <= mid) update(lson, L, R, k);
    if(R > mid) update(rson, L, R, k);
    a[rt] = a[rt<<1] + a[rt<<1|1];
}

inline int qRange(int x, int y){
    int ans = 0;
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        res = 0;
        query(1, 1, n, id[top[x]], id[x]);
        ans += res;
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    res = 0;
    query(1, 1, n, id[x], id[y]);
    ans += res;
    return ans;
}

inline void updRange(int x, int y, int k){
    while(top[x] != top[y]){
        if(dep[top[x]] < dep[top[y]]) swap(x, y);
        update(1, 1, n, id[top[x]], id[x], k);
        x = fa[top[x]];
    }
    if(dep[x] > dep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y], k);
}

inline int qSon(int x){
    res = 0;
    query(1, 1, n, id[x], id[x] + siz[x] - 1);
    return res;
}

inline void updSon(int x, int k){
    update(1, 1, n, id[x], id[x] + siz[x] - 1, k);
}

inline void dfs1(int x, int f, int deep){
    dep[x] = deep;
    fa[x] = f;
    siz[x] = 1;
    int maxson = -1;
    for(Rint i = beg[x]; i; i = nex[i]){
        int y = to[i];
        if(y == f) continue;
        dfs1(y, x, deep + 1);
        siz[x] += siz[y];
        if(siz[y] > maxson) son[x] = y, maxson = siz[y];
    }
}

inline void dfs2(int x, int topf){
    id[x] = ++cnt;
    wt[cnt] = w[x];
    top[x] = topf;
    if(!son[x]) return;
    dfs2(son[x], topf);
    for(Rint i = beg[x]; i; i = nex[i]){
        int y = to[i];
        if(y == fa[x] || y == son[x]) continue;
        dfs2(y, y);
    }
}

int dfsn[maxn], refl[maxn];
vector<int> ed[maxn];
int tot;
void dfs(int x, int fa){
    dfsn[x] = ++tot;
    for(int nxt : ed[x]){
        if(nxt == fa) continue;
        dfs(nxt, x);
    }
}

void solve(){
    cin >> n >> q;
    r = 1;
    set<int> st;
    for(Rint i = 1; i <= n; i++) cin >> w[i], ed[i].clear();
    for(Rint i = 1; i < n; i++){
        int a, b;
        cin >> a >> b;
        add(a, b); add(b, a);
        ed[a].push_back(b);
        ed[b].push_back(a);
    }
    dfs1(r, 0, 1);
    dfs2(r, r);
    tot = 0;
    dfs(1, -1);
    for(int i = 1; i <= n; i++){
        refl[i] = dfsn[i];
        if(w[i]) st.insert(dfsn[i]);
    }
    build(1, 1, n);
    int x, y;
    while(q--){
        cin >> x;
        if(w[x]){
            st.erase(dfsn[x]);
            updRange(x, x, -1);
            w[x] = 0;
        }else{
            st.insert(dfsn[x]);
            updRange(x, x, 1);
            w[x] = 1;
        }
        if(st.empty()){
            cout << "NO" << endl;
            continue;
        }
        int x = *st.begin(), y = *st.rbegin();
        x = refl[x];
        y = refl[y];
        int res = qRange(x, y);
        if(res == st.size()) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}

int T;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> T;
    while(T--){
        solve();
        cout << endl;
    }
    return 0;
}
