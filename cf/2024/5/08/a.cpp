
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
const int mod=1e9+7;
vector<int> e[N];
int v[N],d[N];
void dfs(int x,int dis){
    v[x]=true;
    d[x]=dis;
    for(int nxt:e[x]){
        if(v[nxt])continue;
        dfs(nxt,dis+1);
    }
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)v[i]=0,e[i].clear();
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}