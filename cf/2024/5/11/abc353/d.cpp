/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_d
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> pre(n+1),tim(n+1);
    for(int i=1;i<=n;i++){
        pre[i]=(pre[i-1]+a[i-1])%mod;
    }
    for(int i=n-1;i>=0;i--){
        ll t=1,cur=a[i];
        while(cur)t=t*10%mod,cur/=10;
        tim[i]=(tim[i+1]+t)%mod;
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ans=(ans+pre[n]-pre[i+1])%mod;
        ans=(ans+a[i]*tim[i+1])%mod;
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