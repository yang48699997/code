#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=2e5+5;
int fa[N],siz[N];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    siz[x]+=siz[y];
    fa[y]=x;
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> e(n),ee(n);
    vector<int> deg(n);
    for(int i=0;i<n;i++){
        fa[i]=i;
        siz[i]=1;
    }
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x;
        x--;
        e[i].push_back(x);
        ee[x].push_back(i);
        deg[x]++;
        merge(i,x);
    }
    queue<int> q;
    for(int i=0;i<n;i++){
        if(deg[i]==0)q.push(i);
    }
    while(!q.empty()){
        int cur=q.front();
        siz[find(cur)]--;
        q.pop();
        for(int nxt:e[cur]){
            deg[nxt]--;
            if(deg[nxt]==0)q.push(nxt);
        }
    }
    ll ans=0;
    vector<ll> cnt(n);
    for(int i=0;i<n;i++){
        if(deg[i]==0)cnt[i]=1;
        else {
            cnt[i]=siz[find(i)];
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur=q.front();
        q.pop();
        ans+=cnt[cur];
        for(int nxt:ee[cur]){
            if(deg[nxt])continue;
            cnt[nxt]+=cnt[cur];
            q.push(nxt);
        }
    }
    cout<<ans;
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}