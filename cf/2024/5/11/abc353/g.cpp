/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_g
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    ll n,c,m;
    cin>>n>>c>>m;
    map<int,ll> pre,suf;
    pre[1]=0;
    suf[1]=0;
    ll ans=0;
    ll t,p;
    while(m--){
        cin>>t>>p;
        auto it1=pre.upper_bound(t);
        it1--;
        ll res=p-c*(t-it1->first)+it1->second;
        auto it2=suf.lower_bound(t);
        if(it2!=suf.end()){
            res=max(res,c*(it2->first-t)+it2->second);
        }
        if(res)
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}