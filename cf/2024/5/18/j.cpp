/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<ll>> a(n+1,vector<ll> (m+1));
    vector<vector<ll>> b(n+1,vector<ll> (m+1));
    vector<vector<ll>> dp(n+1,vector<ll> (m+1,1e18));
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>a[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)cin>>b[i][j];
    dp[1][1]=b[1][1];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(i>1)dp[i][j]=min(dp[i][j],dp[i-1][j]+b[i][j]);
            if(j>1)dp[i][j]=min(dp[i][j],dp[i][j-1]+b[i][j]);
        }
    }
    vector<vector<bool>> ok(n+1,vector<bool> (m+1));
    ok[1][1]=true;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(a[i][j]-a[1][1]-dp[i][j]<0)continue;
            if(ok[i-1][j])ok[i][j]=ok[i-1][j];
            if(ok[i][j-1])ok[i][j]=ok[i][j-1];
        }
    }
    for(int i=1;i<=n;i++){
        if(ok[i][m]){
            cout<<"YES";
            return;
        }
    }
    for(int i=1;i<=m;i++){
        if(ok[n][i]){
            cout<<"YES";
            return;
        }
    }
    cout<<"NO";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}