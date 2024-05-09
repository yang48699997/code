/*
 * Author: Ram
 * Date: 2024-05-03
 * Source: https://www.luogu.com.cn/problem/P4017
*/
#include <bits/stdc++.h>
using namespace std;
const int mod=80112002;
#define endl '\n'
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    queue<int> q;
    vector<vector<int>> e(n+1);
    vector<int> deg(n+1);
    while(m--){
        int x,y;
        cin>>x>>y;
        deg[y]++;
        e[x].push_back(y);
    }
    ll ans=0;
    vector<ll> res(n+1);
    for(int i=1;i<=n;i++)if(deg[i]==0)q.push(i),res[i]=1;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        if(e[x].size()==0){
            ans=(ans+res[x])%mod;
            continue;
        }
        for(int nxt:e[x]){
            deg[nxt]--;
            res[nxt]=(res[x]+res[nxt])%mod;
            if(deg[nxt]==0){
                q.push(nxt);
            }
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