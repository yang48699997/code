#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int T;

ll gcd(ll x,ll y){
    while(y){
        ll t=y;
        y=x%y;
        x=t;
    }
    return x;
}
void solve(){
    int n,m,k;
    cin>>n>>m>>k;
    vector<vector<ll>> a(n,vector<ll> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>a[i][j];
    }    
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<ll> sum(2);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)sum[s[i][j]-'0']+=a[i][j];
    }
    vector<vector<ll>> pre(n+1,vector<ll>(m+1));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            ll p=1;
            if(s[i-1][j-1]=='0')p=-p;
            pre[i][j]=p+pre[i-1][j]+pre[i][j-1]-pre[i-1][j-1];
        }
    }
    ll g=-1;
    for(int i=k;i<=n;i++){
        for(int j=k;j<=m;j++){
            ll p=pre[i][j]-pre[i-k][j]-pre[i][j-k]+pre[i-k][j-k];
            if(p==0)continue;
            if(g==-1)g=abs(p);
            else g=gcd(g,abs(p));
        }
    }
    if(sum[0]==sum[1]){
        cout<<"YES";
        return;
    }
    if(g==-1||abs(sum[0]-sum[1])%g!=0)cout<<"NO";
    else cout<<"YES";
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