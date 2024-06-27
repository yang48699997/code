/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e5+5;
int a[N],dp[N];
vector<int> e[N];
int n,ans;
int T;
bool dfs(int x,int fa){
    bool ok=true;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        bool key=dfs(nxt,x);
        if(!key)ok=false;
    }
    if(fa!=-1&&a[x]*2<a[fa])ok=false;
    dp[x]=ok;
    return ok;
}
void reroot(int x,int fa){
    int c1=0,c2=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        if(dp[nxt])c2++;
        else c1++;
    }
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        
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
    dfs(1,-1);
    ans=0;
    if(dp[1])ans++;
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