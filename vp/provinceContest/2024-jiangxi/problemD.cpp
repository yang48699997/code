#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
const int mod = 998244353;
int T;
const int mx = 1e6+5;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<map<int,int>> cnt(20);
    for(int i=0;i<n;i++){
        int sq=sqrt(a[i]);
        for(int j=2;j<=sq;j++){
            if(a[i]%j!=0)continue;
            int c=0;
            while(a[i]%j==0){
                cnt[c++][j]++;
                a[i]/=j;
            }
        }
        if(a[i]>1)cnt[0][a[i]]++;
    }
    vector<ll> res(n+1,1);
    for(auto &mp:cnt){
        for(auto [x,c]:mp){
            res[n-c+1]=res[n-c+1]*x%mod;
        }
    }
    ll ans=0;
    for(int i=1;i<=n;i++){
        res[i]=res[i]*res[i-1]%mod;
        ans=(ans+res[i])%mod;
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