/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_c
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    ll ans=0;
    int mx=0;
    for(int i=0;i<n;i++)cin>>a[i]>>b[i],ans+=a[i],mx=max(b[i]-a[i],mx);
    ans+=mx;
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}