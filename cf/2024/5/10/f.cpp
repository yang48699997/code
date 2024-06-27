/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1209/problem/F
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod=1e9+7;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<pair<int,int>>> e(n+1+m*4);
    int tot=n;
    for(int i=1;i<=m;i++){
        int x,y;
        cin>>x>>y;
        int cur=i;
        vector<int> num;
        while(cur)num.push_back(cur%10),cur/=10;
        int pre=x;
        for(int j=num.size()-1;j>0;j--){
            e[pre].push_back({++tot,num[j]});
            pre=tot;
        }
        e[pre].push_back({y,num[0]});
        pre=y;
        for(int j=num.size()-1;j>0;j--){
            e[pre].push_back({tot-num.size()+j+1,num[j]});
            pre=tot-num.size()+j+1;
        }
        e[pre].push_back({x,num[0]});
    }
    vector<int> v(tot+1);
    vector<ll> ans(tot+1);
    queue<vector<int>> q;
    q.push({1});
    v[1]=1;
    while(!q.empty()){
        auto &p=q.front();
        vector<vector<int>> nxt(10);
        for(int i=0;i<10;i++){
            for(int x:p){
                for(auto [y,val]:e[x]){
                    if(v[y]||val!=i)continue;
                    v[y]=1;
                    ans[y]=(ans[x]*10+i)%mod;
                    nxt[i].push_back(y);
                }
            }
        }
        for(auto &ver:nxt){
            if(ver.size()!=0)q.push(ver);
        }
        q.pop();
    }
    for(int i=2;i<=n;i++)cout<<ans[i]<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}