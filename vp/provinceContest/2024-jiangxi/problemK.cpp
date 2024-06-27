#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int mod=998244353;
void solve(){
    int m;
    cin>>m;
    vector<int> dp(m+1);
    dp[1]=1;
    int pre=1;
    for(int i=2;i<=m;i++){
        dp[i]=(pre+1)%mod;
        pre=(pre+dp[i])%mod;
    }
    cout<<dp[m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}