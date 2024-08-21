#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int T;
const int N=1e6+5;
const int mod=998244353;

ll powMod(ll x,ll y){
    ll res = 1;
    while(y){
        if(y&1)res = res * x %mod;
        x = x * x % mod;
        y >>= 1;
    };
    return res;
};
ll f[N*2];

void init(){
    f[0]=1;
    for(int i=1;i<N*2;i++)f[i]=f[i-1]*i%mod;
}

void solve(){
    ll n;
    cin>>n;
    if(n==2){
        cout<<1;
        return;
    }
    ll ans=n*f[2*n-4]%mod*powMod(f[n-1],mod-2)%mod*powMod(f[n-3],mod-2)+f[2*n-3]*powMod(f[n-1],mod-2)%mod*powMod(f[n-2],mod-2);
    ans%=mod;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    init();
    cin>>T;
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}