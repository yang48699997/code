/*
 * Author: Ram
 * Date: 2024-05-15
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
int n;
const int N=1e5+5;
int a[N],dp[N];
int ans;
vector<int> e[N];
void dfs(int x,int fa){
    bool ok=true;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        dfs(nxt,x);
        if(a[nxt]*2<a[x])ok=false;
        else if(!dp[nxt])ok=false;
    }
    dp[x]=ok;
}
void reroot(int x,int fa){
    // cout<<x<<' '<<fa<<endl;
    if(fa!=-1&&a[fa]*2<a[x])return;
    int c=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        if(!dp[nxt]||a[nxt]*2<a[x])c++;
    }
    if(c==0)ans++;
    if(c>1)return;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        if(!dp[nxt]||a[nxt]*2<a[x])reroot(nxt,x);
        else if(c==0)reroot(nxt,x);
    }
}
void solve(){
    cin>>n;    
    for(int i=1;i<=n;i++)cin>>a[i],e[i].clear();
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    ans=0;
    dfs(1,-1);
    reroot(1,-1);
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