#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int mod=998244353;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<vector<int>> dp(n+1,vector<int>(k+1));
    vector<int> pre(k+1);
    pre[0]=1;
    dp[0][0]=1;
    for(int i=1;i<=n;i++){
        for(int j=k;j>0;j--){
            dp[i][j]=(dp[i][j]+pre[j-1])%mod;
            if(i!=n&&i>2){
                dp[i][j]=(dp[i][j]-dp[i-2][j-1])%mod;
                if(dp[i][j]<0)dp[i][j]+=mod;
            }
        }
        dp[i][k]=(dp[i][k]+pre[k])%mod;
        if(i!=n&&i>2){
            dp[i][k]=(dp[i][k]-dp[i-2][k])%mod;
            if(dp[i][k]<0)dp[i][k]+=mod;
        }
        for(int j=0;j<=k;j++)pre[j]=(pre[j]+dp[i][j])%mod;
    }
    cout<<dp[n][k];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}