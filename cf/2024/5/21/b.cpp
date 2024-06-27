/*
 * Author: Ram
 * Date: 2024-05-22
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=2e5+5;
int T;
int n;
ll a[N];
vector<int> e[N];
ll dp1[N],dp2[N];
int v1[N],v2[N];
int sz[N];
void dfs1(int x,int fa){
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        dfs1(nxt,x);
        sz[x]+=sz[nxt];
    }
    return;
}
void dfs(int x,int fa,int cnt){
    if(cnt%2==0&&v2[x])return;
    if(cnt%2==1&&v1[x])return;
    int c1=0;
    vector<ll> pp,mus(3); 
    ll res=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        dfs(nxt,x,0);
        dfs(nxt,x,1);
        if(sz[nxt]%2==1){
            c1++;
            pp.push_back(dp2[nxt]-dp1[nxt]);
            res+=dp1[nxt];
        }
        else{
            mus[0]+=dp1[nxt];
            mus[1]+=dp2[nxt];
            mus[2]+=max(dp1[nxt],dp2[nxt]);
        }
    }
    sort(pp.begin(),pp.end());
    if(c1>0)res+=mus[2];
    else if(cnt%2==1)res+=mus[1];
    else res+=mus[0];
    int i=0;
    if(cnt%2==0)i=(c1+1)/2;
    else i=c1/2;
    for(;i<pp.size();i++)res+=pp[i];
    if(cnt%2==0)dp2[x]+=res,v2[x]=1;
    else dp1[x]+=res,v1[x]=1;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i],e[i].clear(),dp1[i]=dp2[i]=0,v1[i]=v2[i]=0,sz[i]=1;
    for(int i=1;i<=n;i++)dp2[i]+=a[i];
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(1,-1);
    dfs(1,-1,1);
    cout<<dp1[1];
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