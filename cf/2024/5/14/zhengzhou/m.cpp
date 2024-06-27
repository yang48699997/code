/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=3e5+5;
int n;
ll a[N],b[N];
int T;

bool check(ll x){
    ll l=0,r=1e9;
    for(int i=0;i<n;i++){
        ll cur=b[i]*x;
        r=min(r,a[i]+cur);
        l=max(l,a[i]-cur);
    }
    return l<=r;
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i]; 
    for(int i=0;i<n;i++)cin>>b[i]; 
    ll l=0,r=1e9;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<r+1<<endl;
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