#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int mod=998244353;

ll powM(ll x,ll y){
    ll res=1;
    while(y){
        if(y&1)res=res*x%mod;
        y>>=1;
        x=x*x%mod;
    }
    return res;
}
void solve(){
    ll n,k;
    cin>>n>>k;
    ll ans=1;
    ll sum=(n+1)*n/2;
    ll p1=powM(n,mod-2);
    ll p2=(n-1)*powM(n,mod-2)%mod;
    ll p3=(n*n-2*n+1)%mod*powM(n*n%mod,mod-2)%mod;
    for(int i=0;i<k;i++){
        ll res1=sum%mod*powM(n,mod-2)%mod*p1%mod;
        ll res2=(sum-ans)%mod;
        if(res2<0)res2+=mod;
        res2=p2*res2%mod*powM(n-1,mod-2)%mod*p1%mod;
        // cerr<<res1<<' '<<res2;
        ans=(res1+res2+p3*ans)%mod;
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