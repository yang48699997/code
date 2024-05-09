/*
 * Author: Ram
 * Date: 2024-04-25
 * Source: https://codeforces.com/contest/1547/problem/G
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
const int N=4e5+5;
int n,m;
int v[N];
vector<int> e[N];
void dfs(int x){
    v[x]++;
    for(int nxt:e[x]){
        if(v[nxt]<2){
            dfs(nxt);
        }
    }
}
void solve(){
    cin>>n>>m;
    for(int i=1;i<=n;i++)v[i]=0,e[i].clear();
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
    }
    vector<int> deg(n+1);
    dfs(1);
    for(int i=1;i<=n;i++){
        if(!v[i])continue;
        for(int nxt:e[i])deg[nxt]++;
    }
    queue<int> q;
    vector<bool> cyc(n+1,true); 
    for(int i=1;i<=n;i++){
        if(deg[i]==0&&v[i])q.push(i);
    }
    while(!q.empty()){
        int x=q.front();
        q.pop();
        cyc[x]=false;
        for(int nxt:e[x]){
            deg[nxt]--;
            if(deg[nxt]==0)q.push(nxt);
        }
    }
    for(int i=1;i<=n;i++){
        if(v[i]&&cyc[i]){
            cout<<-1<<' ';
            continue;
        }
        cout<<v[i]<<' ';
    }
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