#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    int n;
    ll c;
    cin>>n>>c;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> ans(n);
    vector<ll> suf(n+1);
    vector<ll> pp(n+1);
    for(int i=n-1;i>=0;i--){
        suf[i]=max(suf[i+1],a[i]);
    }
    for(int i=1;i<=n;i++){
        pp[i]=max(pp[i-1],a[i-1]);
    }
    if(a[0]+c<suf[1])ans[0]=1;
    ll pre=a[0];
    for(int i=1;i<n;i++){
        ll mx=suf[i+1];
        if(a[i]>a[0]+c&&a[i]>=suf[i+1]&&a[i]>pp[i]){
            ans[i]=0;
        }else{
            ll cur=pre+a[i]+c;
            if(cur<mx){
                ans[i]=i+1;
            }else ans[i]=i;
        } 
        pre+=a[i];
    }
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
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