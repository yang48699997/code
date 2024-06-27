/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_c
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    const ll mod=1e8;
    ll sum=0;
    vector<ll> a(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum+=a[i]*(n-1);
    }
    sort(a.begin(),a.end());
    for(int i=0;i<n;i++){
        auto it=lower_bound(a.begin(),a.end(),mod-a[i]);
        int d=it-a.begin();
        d=n-d;
        sum-=mod/2*d;
        if(a[i]*2>=mod)sum+=mod/2;
    }
    cout<<sum;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}