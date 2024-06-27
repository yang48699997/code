#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
int fa[N],sz[N];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    sz[x]+=sz[y];
    fa[y]=x;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1;
    vector<int> deg(n+1);
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        deg[x]++;
        deg[y]++;
        merge(x,y);
    }
    if(m!=n-1){
        cout<<"No";
        return;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(deg[i]==1)cnt++;
        else if(deg[i]!=2){
            cout<<"No";
            return;
        }
    }
    if(cnt==2&&sz[find(1)]==n)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}