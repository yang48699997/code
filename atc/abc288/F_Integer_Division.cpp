#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod=998244353;

void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<ll> dp(n);
    ll sum=s[0]-'0'+1;
    dp[0]=s[0]-'0';
    for(int i=1;i<n;i++){
        ll cur=s[i]-'0';
        dp[i]=sum*cur%mod;
        dp[i]=(dp[i-1]*10+dp[i])%mod;
        sum=(sum+dp[i])%mod;
    }
    cout<<dp[n-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}