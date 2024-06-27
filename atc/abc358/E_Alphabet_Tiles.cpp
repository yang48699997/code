#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int mod=998244353;
using ll = long long;
const int N=1e3+5;

void solve(){
    int k;
    cin>>k;
    vector<int> c(26);
    for(int i=0;i<26;i++)cin>>c[i];
    vector<ll> dp(k+1);
    dp[0]=1;
    vector<vector<int>> p(N,vector<int> (N));
    p[0][0]=1;
    for(int i=1;i<N;i++){
        p[i][0]=1;
        for(int j=1;j<=i;j++)p[i][j]=(p[i-1][j]+p[i-1][j-1])%mod;
    }
    for(int i=0;i<26;i++){
        for(int j=k;j>=0;j--){
            for(int q=1;q<=c[i];q++){
                if(j-q<0)continue;
                dp[j]=(dp[j]+dp[j-q]*p[j][q])%mod;
            }
        }
    }
    ll ans=0;
    for(int i=1;i<=k;i++){
        ans=(ans+dp[i])%mod;
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