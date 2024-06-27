#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
const int N=2e5+5;

vector<int> e[N];
int dp1[N],dp2[N],vv[N],v[N];
int n;
int dfs1(int x,int fa){
    dp1[x]=dp2[x]=1;
    int mi=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        dfs1(nxt,x);
        dp1[x]+=dp1[nxt]+1;
        mi=max(mi,dp1[nxt]-dp2[nxt]+1);
    }
    dp2[x]=dp1[x]-mi;
    return dp2[x];
}

int dfs(int x,int t,int fa){
    if(x==t){
        vv[x]=1;
        return 1;
    }
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        if(dfs(nxt,t,x)){
            vv[x]=1;
            return 1;
        }
    }
    return 0;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)e[i].clear();
    int s,t,x,y;
    cin>>s>>t;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int ans=0;
    vector<int> vis(n+1);
    queue<pair<int,int>> q;
    int cnt=0;
    q.emplace(s,0);
    vis[s]=1;
    while(!q.empty()){
        auto [nxt,d]=q.front();
        q.pop();
        cnt=d;
        if(nxt==t)break;
        for(int y:e[nxt]){
            if(vis[y])continue;
            vis[y]=1;
            q.emplace(y,d+1);
        }
    }
    for(int i=1;i<=n;i++)vv[i]=0;
    dfs(s,t,-1);
    int p=s,fa=-1;
    for(int i=0;i<cnt/2;i++){
        for(int nxt:e[p]){
            if(nxt==fa)continue;
            if(vv[nxt]){
                fa=p;
                p=nxt;
                break;
            }
        }
    }
    // cout<<p<<endl;
    ans=dfs1(p,-1)+cnt/2-1;
    if(cnt%2)ans++;
    cout<<ans;
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