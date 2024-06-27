#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
ll gcd(ll x,ll y){
    while(y){
        ll temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll res=a[0];
    for(int i=1;i<n;i++){
        ll g=gcd(res,a[i]);
        res=res/g*a[i];
    }
    ll tot=0;
    for(int i=0;i<n;i++){
        tot+=res/a[i];
    }
    if(tot>=res){
        cout<<-1;
        return;
    }
    for(int i=0;i<n;i++)cout<<(res/a[i])<<' ';
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