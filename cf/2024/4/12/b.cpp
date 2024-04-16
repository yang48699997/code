/*
 * Author: Ram
 * Date: 2024-04-12
 * Source: https://codeforces.com/contest/1954/problem/D
*/
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'
const int mod=998244353;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<ll> sum(5005);
    sum[0]=1;
    ll ans=0;
    for(int i=0;i<n;i++){
        int x=a[i];
        for(int j=5000;j>0;j--){
            if(j-x<0)break;
            sum[j]=(sum[j]+sum[j-x])%mod;
            if(x*2>=j)ans=(ans+sum[j-x]*x)%mod;
            else ans=(ans+sum[j-x]*((j+1)/2))%mod;
        }
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