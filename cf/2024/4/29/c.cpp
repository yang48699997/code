/*
 * Author: Ram
 * Date: 2024-04-29
 * Source: https://codeforces.com/contest/1969/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
using ll = long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    ll inf=1e18;
    vector<vector<ll>> dp(n+1,vector<ll> (k+1,inf));
    for(int i=0;i<=k;i++)dp[0][i]=0;
    for(int i=1;i<=n;i++)dp[i][0]=dp[i-1][0]+a[i];
    for(int i=1;i<=k;i++){
        for(int j=1;j<=n;j++){
            dp[j][i]=dp[j-1][i]+a[j];
            ll mi=a[j],sum=a[j];
            for(int m=1;m<=min(k,j-1)&&m<=i;m++){
                sum+=a[j-m];
                mi=min(a[j-m],mi);
                dp[j][i]=min(dp[j][i],dp[j-m-1][i-m]+mi*(m+1));
            }
        }
    }
    cout<<dp[n][k];
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