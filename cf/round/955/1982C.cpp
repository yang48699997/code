#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
using ll = long long;

void solve(){
    int n;
    ll l,r;
    cin>>n>>l>>r;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]+=a[i-1];
    }    
    vector<int> cnt(n+2);
    for(int i=n;i>=0;i--){
        auto it=lower_bound(a.begin(),a.end(),a[i]+l);
        if(it==a.end())cnt[i]=cnt[i+1];
        else{
            int m=it-a.begin();
            if(a[m]-a[i]<=r)cnt[i]=max(cnt[i+1],cnt[m]+1);
            else cnt[i]=cnt[i+1];
        }
    }
    cout<<cnt[0];
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