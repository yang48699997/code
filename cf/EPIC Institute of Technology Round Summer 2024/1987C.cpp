#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<ll> h(n);
    for(int i=0;i<n;i++)cin>>h[i];
    ll ans=h[n-1];
    for(int i=n-2;i>=0;i--){
        h[i]=max(h[i],h[i+1]+1);
    }
    cout<<h[0];
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