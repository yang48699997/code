#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
bool check(ll a,ll x){
    ll mi=x-1;
    ll mx=x*(x-1)/2;
    if(mi<=a&&mx>=a)return true;
    return false;
}
void solve(){
    string s;
    cin>>s;
    ll a=0;
    int i=0;
    for(;s[i]!='/';i++){
        a=a*10+(s[i]-'0');
    }    
    ll b=0;
    for(i++;i<s.length();i++)b=b*10+(s[i]-'0');
    vector<vector<ll>> e(1,vector<ll> ());
    vector<ll> v(1);
    ll cnt=1;
    int N=1e6;
    for(ll i=b;i<=N;i+=b){
        ll x=i;
        if(check(i/b*a,x)){
            ll tar=i/b*a;
            ll mx=x*(x-1)/2;
            mx-=tar;
            cout<<i<<' '<<i-1<<endl;
            for(int j=x;j>1;j--){
                ll p=max(1LL,j-1-mx);
                cout<<j<<' '<<p<<endl;;
                mx-=j-p-1;
            }
            return;
        }
    }
    cout<<"impossible";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}