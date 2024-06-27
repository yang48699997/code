#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll x,y,z,k;
    cin>>x>>y>>z>>k;
    ll mx=0;
    for(ll i=1;i<=x;i++){
        for(ll j=1;j<=y;j++){
            ll p=k/i/j;
            if(p>z||p<=0)continue;
            if(i*j*p!=k)continue;
            ll res=(x-i+1)*(y-j+1)*(z-p+1);
            mx=max(mx,res);
        }
    }
    cout<<mx;
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