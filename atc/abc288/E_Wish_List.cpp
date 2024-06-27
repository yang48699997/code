#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>b[i];
    vector<int> x(m);
    for(int i=0;i<m;i++)cin>>x[i],x[i]--;
    vector<vector<ll>> dp(n+1,vector<ll>(n+1,1e18));
    dp[0][0]=0;
    vector<int> v(n);
    for(int i:x)v[i]=1;
    for(int i=1;i<=n;i++){
        ll res=1e18;
        if(!v[i-1])
        for(int j=0;j<i;j++)dp[i][j]=dp[i-1][j];
        for(int j=0;j<i;j++){
            res=min(res,b[i-1-j]);
            dp[i][j+1]=min(dp[i][j+1],res+dp[i-1][j]+a[i-1]);
        }
    }
    ll ans=1e18;
    for(int i=0;i<=n;i++)ans=min(ans,dp[n][i]);
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}