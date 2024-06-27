#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<ll> a(n),b(n+1);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<=n;i++)cin>>b[i];
    ll ans=1;
    for(int i=0;i<n;i++)ans+=abs(a[i]-b[i]);
    ll cur=b.back();
    ll res=1e18;
    for(int i=0;i<n;i++){
        if(b[i]>=a[i]){
            if(cur>=a[i]){
                if(cur<=b[i]){
                    res=0;
                }else{
                    res=min(res,(cur-b[i]));
                }
            }else{
                res=min(res,(a[i]-cur));
            }
        }else{
            swap(a[i],b[i]);
            i--;
        }
    }
    ans+=res;
    cout<<ans;
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