#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod=1e9+7;

#define endl '\n'

int T;
map<pair<ll,int>,ll> mp; 
ll cal(ll n,int k){
    if(!n||!k)return 1;
    if(n<(1LL<<k<<1)){
        if(n==(1LL<<k<<1)-1)n--;
        n%=mod;
        return (n+2)*(n+1)/2%mod;
    }
    if(mp.count({n,k}))return mp[{n,k}];
    int l=-1;
    for(int i=0;i<60;i++){
        if(n>=(1LL<<i))l++;
        else break;
    }
    ll res=(cal((1LL<<l)-1,k)+cal(n-(1LL<<l),k-1))%mod;
    mp[{n,k}]=res;
    return res;
}

void solve(){
    ll n;
    int k;
    cin>>n>>k;
    cout<<cal(n-1,k);
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