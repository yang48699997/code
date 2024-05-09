/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_f
*/
#include <bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
#define endl '\n'
int fa[20];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    fa[y]=x;
}
vector<pii> e[20];
int num[20],seen[20];
void dfs(int x,int d){
    num[x]=d;
    seen[x]=1;
    for(auto [nxt,c]:e[x]){
        if(seen[nxt])continue;
        merge(x,nxt);
        dfs(nxt,d+c);
    }
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)e[i].clear();
    while(m--){
        int x,y,c;
        cin>>x>>y>>c;
        e[x].push_back({y,c});
        e[y].push_back({x,-c});
    }
    for(int i=1;i<=n;i++)fa[i]=i,seen[i]=0;
    vector<int> g(n+1,1);
    queue<int> q;
    for(int i=1;i<=n;i++){
        if(seen[i])continue;
        dfs(i,0);
    }
    vector<int> mi(n+1);
    for(int i=1;i<=n;i++){
        int f=find(i);
        mi[f]=min(mi[f],num[i]);
    }
    for(int i=1;i<=n;i++){
        int f=find(i);
        g[f]|=1<<(num[i]-mi[f]);
    }
    vector<int> mask;
    for(int i=1;i<=n;i++)if(fa[i]==i)mask.push_back(g[i]);
    vector<vector<int>> dp(mask.size()+1,vector<int> (1<<n,0));
    dp[0][0]=1;
    for(int i=1;i<=mask.size();i++){
        int cur=mask[i-1];
        while(cur<1<<n){
            for(int j=1;j<1<<n;j++){
                if((j|cur)!=j)continue;
                dp[i][j]|=dp[i-1][j^cur];
            }
            cur<<=1;
        }
    }
    vector<set<int>> v(n+1);
    vector<vector<int>> vv(n+1,vector<int>(1<<n));
    function<void(int,int)> df=[&](int i,int mx)->void{
        if(i==0)return;
        if(vv[i][mx])return;
        int cur=mask[i-1];
        int cnt=0;
        while(cur<1<<n){
            if(dp[i-1][mx^cur]){
                v[i].insert(cnt);
                df(i-1,mx^cur);
            }
            cur<<=1;
            cnt++;
        }
        vv[i][mx]=true;
    };
    df(mask.size(),(1<<n)-1);
    vector<int> ref(n+1);
    int p=1;
    for(int i=1;i<=n;i++){
        if(fa[i]==i)ref[p++]=i;
    }
    vector<int> ans(n+1);
    for(int i=1;i<=mask.size();i++){
        if(v[i].size()>1){
            for(int j=1;j<=n;j++){
                if(fa[j]==ref[i]){
                    ans[j]=-1;
                }
            }
        }else {
            for(int j=1;j<=n;j++){
                if(fa[j]==ref[i]){
                    ans[j]=n-*v[i].begin()-num[j]+mi[fa[j]];
                }
            }
        }
    }
    for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}