#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod = 998244353;
ll powMod(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
void solve(){
    ll n;
    cin>>n;
    string s=to_string(n);
    ll len=s.length();
    ll p=(n%(mod-1))*len%(mod-1);
    ll p3=n*len;
    ll res=powMod(10,p);
    ll res3=powMod(10,p3);
    res--;
    if(res<0)res+=mod;
    res=res*powMod(9,mod-2)%mod;
    ll p2=len;
    ll res2=powMod(10,p2);
    res2--;
    if(res2<0)res2+=mod;
    res2=res2*powMod(9,mod-2)%mod;
    ll ans=res*powMod(res2,mod-2)%mod;
    ans=ans*(n%mod)%mod;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}