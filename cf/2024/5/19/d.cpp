/*
 * Author: Ram
 * Date: 2024-05-19
 * Source: https://codeforces.com/problemset/problem/1884/D
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n,x;
    cin>>n;
    vector<int> a(n+1);
    for(int i=0;i<n;i++){
        cin>>x;
        a[x]++;
    }
    vector<ll> dp(n+1);
    for(int i=n;i>0;i--){
        ll sum=0;
        for(int j=i;j<=n;j+=i)sum+=a[j];
        dp[i]=sum*(sum-1)/2;
        for(int j=i+i;j<=n;j+=i)dp[i]-=dp[j];
    }
    ll ans=n;
    ans=ans*(ans-1)/2;
    for(int i=1;i<=n;i++){
        if(!a[i])continue;
        for(int j=i;j<=n;j+=i)ans-=dp[j],dp[j]=0;
    }
    cout<<ans;
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