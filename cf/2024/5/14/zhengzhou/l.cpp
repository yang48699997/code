/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
ll p[31];
void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    sort(a.begin(),a.end());
    for(ll i=0;i<=30;i++)p[i]=i*i*i*i;
    vector<ll> dp(m+1,1e18);
    dp[0]=0;
    for(int i=0;i<m;i++){
        ll x=a[i];
        for(int j=i;j>=max(0,i-29);j--){
            dp[i+1]=min(dp[i+1],dp[j]+x+p[i-j+1]);
        }
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