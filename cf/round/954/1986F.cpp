#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

using ll = long long;
const int N = 1e5 + 5;
int T;
int dfn[N],low[N];
int son[N],ok[N];
vector<int> e[N];
int tar[N*2];
int tot;

void tarjan(int x,int eid){
    dfn[x]=low[x]=++tot;
    son[x]=1;
    for(int y:e[x]){
        int nxt=tar[y];
        if(!dfn[nxt]){
            tarjan(nxt,y);
            son[x]+=son[nxt];
            low[x]=min(low[x],low[nxt]);
            if(low[nxt]>dfn[x])ok[nxt]=1;
        }else if((y^eid)!=1){
            low[x]=min(low[x],dfn[nxt]);
        }
    }
}

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        dfn[i]=low[i]=0;
        son[i]=ok[i]=0;
        e[i].clear();
    }
    int cnt=-1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        tar[++cnt]=y;
        e[x].push_back(cnt);
        tar[++cnt]=x;
        e[y].push_back(cnt);
    }
    tot=0;
    tarjan(1,-1);
    ll sum=(ll)n*(n-1);
    ll ans=sum;
    for(int i=1;i<=n;i++){
        // cerr<<ok[i]<<" \n"[i==n];
        if(!ok[i])continue;
        ll cnt1=son[i];
        ll cnt2=son[1]-son[i];
        ans=min(ans,cnt1*(cnt1-1)+cnt2*(cnt2-1));
    }
    cout<<ans/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}