/*
 * Author: Ram
 * Date: 2024-05-09
 * Source: https://codeforces.com/problemset/problem/938/D
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,ll>>> e(n*2+1);
    for(int i=0;i<m;i++){
        int x,y;
        ll w;
        cin>>x>>y>>w;
        x--;
        y--;
        e[x].emplace_back(y,w*2);
        e[y].emplace_back(x,w*2);
    }
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        e[i].emplace_back(i+n,a[i]);
        e[i+n].emplace_back(i,a[i]);
        e[i+n].emplace_back(n*2,0);
        e[n*2].emplace_back(i+n,0);
    }
    vector<ll> dis(n*2+1,1e18);
    vector<int> v(n*2+1);
    dis[n*2]=0;
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> q;
    q.push({0,n*2});
    while(!q.empty()){
        auto [d,x]=q.top();
        q.pop();
        if(v[x])continue;
        v[x]=1;
        for(auto [nxt,dd]:e[x]){
            if(d+dd>=dis[nxt])continue;
            dis[nxt]=d+dd;
            q.push({dis[nxt],nxt});
        }
    }
    for(int i=0;i<n;i++)cout<<dis[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}