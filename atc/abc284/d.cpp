#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
ll sqrt(ll x){
    ll l=1,r=x;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(x/mid>=mid)l=mid+1;
        else r=mid-1;
    }
    return l-1;
}
void solve(){
    ll x;
    cin>>x;
    ll l=2;
    while(x%l!=0){
        l++;
    }
    ll r=x/l;
    if(r%l==0)cout<<l<<' '<<r/l;
    else cout<<sqrt(r)<<' '<<l;
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