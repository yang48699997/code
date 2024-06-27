#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
int fa[105];
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
    int n,m;
    cin>>n>>m;
    for(int i=0;i<=n;i++)fa[i]=i;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        merge(x,y);
    }
    int ans=0;
    for(int i=1;i<=n;i++)if(fa[i]==i)ans++;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}