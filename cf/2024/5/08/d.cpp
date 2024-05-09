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
    ll ans=0;
    vector<vector<ll>> dp(2*n+1,vector<ll> (n+1));
    for(int i=1;i<=n;i++)dp[0][i]=a[i-1];
    for(int i=1;i<=n*2;i++){
        for(int j=1;j<=n;j++){
            dp[i][j]=max(dp[i][j],dp[i-1][j-1]);
            if(j+1<=n)dp[i][j]=max(dp[i][j],dp[i-1][j+1]);
        }
    }
}   

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}