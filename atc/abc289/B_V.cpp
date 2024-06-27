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
    fa[x]=fa[y];
}
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=1;i<=n;i++)fa[i]=i;
    for(int i=0;i<m;i++)cin>>a[i],merge(a[i],a[i]+1);
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        int f=find(i);
        if(v[f])continue;
        v[f]=1;
        for(int j=f;j>=i;j--)cout<<j<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}