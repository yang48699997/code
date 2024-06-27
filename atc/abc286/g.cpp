#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
int fa[N];

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
void solve(){
    int n,m,k,x;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i;
    vector<pair<int,int>> e(m+1);
    vector<int> v(m+1);
    for(int i=1;i<=m;i++)cin>>e[i].first>>e[i].second;
    cin>>k;
    for(int i=1;i<=k;i++){
        cin>>x;
        v[x]=1;
    }
    for(int i=1;i<=m;i++){
        if(v[i])continue;
        merge(e[i].first,e[i].second);
    }
    vector<int> deg(n+1);
    for(int i=1;i<=m;i++){
        if(find(e[i].first)==find(e[i].second))continue;
        deg[fa[e[i].first]]++;
        deg[fa[e[i].second]]++;
    }
    int cnt=0;
    vector<int> vis(n+1);
    for(int i=1;i<=n;i++){
        x=find(i);
        if(vis[x])continue;
        vis[x]=1;
        if(deg[x]%2)cnt++;
    }
    if(cnt==0||cnt==2)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}