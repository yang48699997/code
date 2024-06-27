/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/D
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long ;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> pre(n+1);
    for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i-1];
    vector<vector<ll>> dp(2*n+1,vector<ll> (n));
    for(int i=0;i<=n*2;i++){
        for(int j=0;j<n;j++){
            int l=max(0,j-i);
            int r=min(n,j+i+1);
            dp[i][j]=max(dp[i][j],pre[r]-pre[j]);
            dp[i][j]=max(dp[i][j],pre[j+1]-pre[l]);
        }
    }
    for(int i=1;i<=2*n;i++){
        for(int j=0;j<n;j++){
            if(j+1<n)dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
            if(j-1>=0)dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        ll cur=0;
        for(int j=1;j<=2*n;j++)cur^=dp[j][i]*j;
        cur+=i+1;
        ans^=cur;
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