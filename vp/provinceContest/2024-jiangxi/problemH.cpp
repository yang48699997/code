#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n,m,k,l;
    cin>>n>>m>>k>>l;
    vector<vector<ll>> g(n+1,vector<ll> (m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>g[i][j];
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            g[i][j]+=g[i][j-1]+g[i-1][j]-g[i-1][j-1];
        }
    }
    ll ans=0;
    int kk = n - k + 1;
    int lll = m -l + 1;
    for(int i=n-k+1;i<=n;i++){
        for(int j=m-l+1;j<=m;j++){
            ll res=g[i][j]-g[i-kk][j]-g[i][j-lll]+g[i-kk][j-lll];
            ans+=abs(res);
        }
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}