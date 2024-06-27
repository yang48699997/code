#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
int v[N];
vector<int> e[N];
int ans;
void dfs(int x){
    ans++;
    v[x]=1;
    if(ans>=1e6)return;
    for(int nxt:e[x]){
        if(v[nxt])continue;
        dfs(nxt);
        if(ans>=1e6)break;
    }
    v[x]=0;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)v[i]=0,e[i].clear();
    int x,y;
    ans=0;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1);
    int mx=1e6;
    cout<<min(ans,mx);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}