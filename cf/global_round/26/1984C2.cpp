#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod=998244353;
int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> p(n+1,1);
    for(int i=1;i<=n;i++)p[i]=p[i-1]*2%mod;
    ll ans=0;
    ll mi=0,cur=0;
    for(int i=0;i<n;i++){
        cur+=a[i];
        mi=min(mi,cur);
    }
    if(mi==0){
        cout<<p[n];
        return ;
    }
    int cnt=0;
    cur=0;
    for(int i=0;i<n;i++){
        cur+=a[i];
        if(cur==mi){
            ans=(ans+p[cnt+n-i-1])%mod;
        }
        if(cur>=0)cnt++;
    }
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