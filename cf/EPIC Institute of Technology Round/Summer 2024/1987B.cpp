#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    ll ans=0;
    int pre=0;
    int mx=0;
    for(int i=0;i<n;i++){
        if(a[i]<pre){
            ans+=pre-a[i];
            mx=max(mx,pre-a[i]);
            a[i]=pre;
        }
        pre=a[i];
    }
    ans+=mx;
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