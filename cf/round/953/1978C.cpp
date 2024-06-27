#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll n,k;
    cin>>n>>k;
    if(k%2==1){
        cout<<"No";
        return;
    }
    vector<ll> ans(n+1);
    for(int i=1;i<=n;i++)ans[i]=i;
    ll l=1,r=n;
    while(l<r){
        if(abs(l-r)*2<=k){
            k-=abs(l-r)*2;
            ans[l]=r;
            ans[r]=l;
            l++;
            r--;
        }else{
            l++;
        }
    }
    if(k==0){
        cout<<"Yes\n";
        ll res=0;
        for(int i=1;i<=n;i++)cout<<ans[i]<<' ';
    }else cout<<"No";
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