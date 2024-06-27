#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll n,a,b;
    cin>>n>>a>>b;
    if(b<=a){
        ll ans=a*n;
        cout<<ans;
        return;
    }
    ll t=b-a;
    ll ans=a*n;
    ans+=t*(t+1)/2;
    t-=n;
    if(t>0)ans-=t*(t+1)/2;
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