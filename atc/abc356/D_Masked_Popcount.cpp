#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod=998244353;


void solve(){
    ll n,m;
    cin>>n>>m;
    ll ans=0;
    ll cur=1;
    for(int i=0;i<61;i++){
        if(!(m>>i&1LL)){
            cur*=2;
            continue;
        }
        ans+=n/cur/2*cur;
        ans%=mod;
        if(n%(cur*2)>=(1LL<<i))ans+=n%(cur*2)-(1LL<<i)+1;
        ans%=mod;
        cur*=2;
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