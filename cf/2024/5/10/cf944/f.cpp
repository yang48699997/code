/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;

void solve(){
    ll r;
    cin>>r;
    ll mi=r*r,mx=(r+1)*(r+1)-1;
    ll ans=0;
    for(ll i=0;i<=r;i++){
        ll l=mi-i*i;
        ll t=mx-i*i;
        l=sqrt(l);
        t=sqrt(t);
        if(l*l+i*i<mi)l++;
        ans+=(t-l+1)*4;
        if(i==0||l==0)ans-=2;
    }
    cout<<ans;
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