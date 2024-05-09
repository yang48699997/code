/*
 * Author: Ram
 * Date: 2024-04-21
 * Source: https://codeforces.com/contest/1957/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
const int mod=1e9+7;
using ll=long long;
void solve(){
    int n,k;
    cin>>n>>k;
    int l=n;
    for(int i=0;i<k;i++){
        int x,y;
        cin>>x>>y;
        if(x==y)l--;
        else l-=2;
    }
    vector<ll> dp(l+10);
    dp[1]=1;
    dp[0]=1;
    for(int i=2;i<=l;i++){
        dp[i]=(dp[i-1]+dp[i-2]*(i-1)*2)%mod;
    }
    cout<<dp[l];
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