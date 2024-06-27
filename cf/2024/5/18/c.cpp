/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=1e6+5;
vector<int> e[N];
int n,m,q,tot,ans;
int A[N],in[N],out[N];
void dfs(int x,int fa){
    in[x]=++tot;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        dfs(nxt,x);
    }
    out[x]=tot;
}
int dfs2(int x,int fa){
    int res=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        res+=dfs2(nxt,x);
    }
    if(res==0&&A[in[x]]){
        ans++;
        res++;
    }
    return res;
}
int tree[N << 2];

void build(int p = 1, int cl = 1, int cr = n){
    if (cl == cr) return void(tree[p] = A[cl]);
    int mid = (cl + cr) >> 1;
    build(p << 1, cl, mid);
    build(p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
int query(int l, int r, int p = 1, int cl = 1, int cr = n){
    if (cl >= l && cr <= r) return tree[p];
    int mid = (cl + cr) >> 1, ans = 0;
    if (mid >= l) ans += query(l, r, p << 1, cl, mid);
    if (mid < r) ans += query(l, r, p << 1 | 1, mid + 1, cr);
    return ans;
}
void update(int l, int r, int d, int p = 1, int cl = 1, int cr = n){
    if (cl >= l && cr <= r) {
        tree[p] += d * (cr - cl + 1);
        return;
    }
    int mid = (cl + cr) >> 1;
    if (mid >= l) update(l, r, d, p << 1, cl, mid);
    if (mid < r) update(l, r, d, p << 1 | 1, mid + 1, cr);
    tree[p] = tree[p << 1] + tree[p << 1 | 1];
}
void solve(){
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)e[i].clear(),A[i]=0;
    int x;
    for(int i=2;i<=n;i++){
        cin>>x;
        e[x].push_back(i);
        e[i].push_back(x);
    }
    tot=ans=0;
    dfs(1,-1);
    for(int i=1;i<=m;i++){
        cin>>x;
        A[in[x]]=1;
    }
    dfs2(1,-1);
    build();
    int choice;
    cout<<ans<<endl;
    while(q--){
        cin>>choice>>x;
        if(choice==1){
            int res=query(in[x],out[x]);
            if(res==0)ans++;
            update(in[x],in[x],1);
        }else{
            int res=query(in[x],out[x]);
            if(res==1)ans--;
            update(in[x],in[x],-1);
        }
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}