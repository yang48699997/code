#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll h,n;
    cin>>h>>n;
    vector<ll> a(n),c(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>c[i];
    auto check=[&](ll p)->bool{
        ll res=0;
        for(int i=0;i<n;i++){
            ll t=p/(c[i]);
            res+=t*a[i];
            if(p-t*(c[i])>0)res+=a[i];
            if(res>=h)return true;
        }
        return res>=h;
    };
    ll l=1,r=1e11;
    while(l<=r){
        ll mid=(r-l)/2+l;
        if(check(mid))r=mid-1;
        else l=mid+1;
    }
    cout<<l;
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