#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod=1e9+7;

int T;
ll powMod(ll y,ll x){
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return res;
}
void solve(){
    int l,r,k;
    cin>>l>>r>>k;
    if(k>=10){
        cout<<0;
        return ;
    }
    int cur=k;
    int mx=9/k+1;
    ll ans=powMod(r,mx)-powMod(l,mx);
    ans%=mod;
    if(ans<0)ans+=mod;
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