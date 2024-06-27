/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/E
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n,k,q;
    cin>>n>>k>>q;
    vector<ll> a(k+1),b(k+1);
    for(int i=1;i<=k;i++)cin>>a[i];
    for(int i=1;i<=k;i++)cin>>b[i];
    while(q--){
        ll d;
        cin>>d;
        auto it=lower_bound(a.begin(),a.end(),d);
        int dis=it-a.begin();
        if(a[dis]==d)cout<<b[dis]<<' ';
        else{
            dis--;
            int ans=b[dis];
            ans+=(d-a[dis])*(b[dis+1]-b[dis])/(a[dis+1]-a[dis]);
            cout<<ans<<' ';
        }
    }
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