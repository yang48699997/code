#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e4+5;
vector<int> e[N];
int dfn[N],low[N];
int stk[N],instk[N];
int scc[N],siz[N];
int tot,top,cnt;
int n,m;

void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk[top++]=x;
    instk[x]=1;
    for(int nxt:e[x]){
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

void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)dfn[i]=low[i]=instk[i]=siz[i]=0,e[i].clear();
    top=tot=cnt=0;
    while(m--){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
    }
    for(int i=1;i<=n;i++)if(!dfn[i])tarjan(i);
    int ans=0;
    for(int i=1;i<=n;i++){
        if(low[i]!=dfn[i])continue;
        if(siz[scc[i]]>1)ans++;
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}