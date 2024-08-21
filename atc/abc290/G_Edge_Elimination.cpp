#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

const ll inf = 1e18;
int T;

void solve(){
    ll ans=inf;
    ll d,k,x;
    cin>>d>>k>>x;
    vector<ll> dp(d+1,1);
    for(int i=1;i<=d;i++)dp[i]=dp[i-1]*k+1;
    for(int i=0;i<=d;i++){
        if(dp[i]<x)continue;
        ll res=1-(i==d);
        ll cur=dp[i]-x;
        for(int j=i-1;j>=0;j--){
            res+=cur/dp[j];
            cur%=dp[j];
        }
        ans=min(ans,res);
    }
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