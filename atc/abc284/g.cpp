#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
ll powMod(ll x,ll mod){
    ll y=mod-2;
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void solve(){
    ll n,mod;
    cin>>n>>mod;
    vector<ll> p(n+1,1);
    vector<ll> pp(n+1,1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]*i%mod;
    for(int i=1;i<=n;i++)pp[i]=pp[i-1]*n%mod;
    ll ans=0;
    ll l=(n-1)%mod;
    for(ll i=2;i<=n;i++){
        ans=(ans+l*pp[n-i]%mod*((i*(i-1)/2)%mod))%mod;
        l=l*(n-i)%mod;
        // ans=(ans+p[n]*powMod(p[n-i],mod)%mod*pp[n-i]%mod*(i*(i-1)/2)%mod)%mod;
    }
    ans=ans*n%mod;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}