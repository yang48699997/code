/*
 * Author: Ram
 * Date: 2024-04-16
 * Source: https://codeforces.com/contest/1954/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
void solve(){
    int n;
    cin>>n;
    const int N=1e5+5;
    vector<ll> a(n);
    vector<ll> v(N);
    ll mx=0;
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        mx=max(mx,a[i]);
        if(i==0||a[i]>a[i-1])v[a[i]]++;
        if(i+1<n&&a[i]<a[i+1])v[a[i]]--;
    }
    for(int i=1;i<N;i++)v[i]+=v[i-1];
    vector<ll> ans(mx+1);
    for(int i=1;i<=mx;i++){
        for(ll j=0;j<=mx;j+=i){
            int y=min(j+i,mx);
            ans[i]+=(v[y]-v[j])*(j/i+1);

        }
        cout<<ans[i]<<' ';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}