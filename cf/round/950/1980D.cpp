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
int check(vector<ll> &a,int j){
    ll pre=0;
    int n=a.size();
    for(int i=0;i<n-1;i++){
        if(i==j)continue;
        if(i+1==j){
            if(i+2==n)break;
            ll cur=gcd(a[i],a[i+2]);
            if(cur<pre)return 0;
            pre=cur;
            continue;
        }
        ll cur=gcd(a[i],a[i+1]);
        if(cur<pre)return 0;
        pre=cur;
    }
    return 1;
}
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<ll> b(n-1);
    for(int i=0;i<n-1;i++){
        b[i]=gcd(a[i],a[i+1]);
    }
    int j=0;
    while(j<n-2&&b[j+1]>=b[j])j++;
    if(j==n-2){
        cout<<"YES";
        return;
    }
    int ok=0;
    for(int i=0;i<3;i++){
        ok|=check(a,i+j);
    }
    if(ok)cout<<"YES";
    else cout<<"NO";
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