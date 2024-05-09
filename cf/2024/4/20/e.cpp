/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_e
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
map<ll,double> mp;
ll x,a;
double X,Y;
double dfs(ll x){
    if(x==0)return 0;
    if(mp.count(x))return mp[x];
    double c1=X+dfs(x/a);
    double c2=6*Y;
    for(int i=2;i<=6;i++)c2+=dfs(x/i);
    c2/=5;
    mp[x]=min(c1,c2);
    return mp[x];
}
void solve(){
    cin>>x>>a>>X>>Y;
    cout<<fixed<<setprecision(8)<<dfs(x);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}