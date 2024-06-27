#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll =long long;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<ll> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<vector<ll>> pre(n+1,vector<ll>(k));
    ll p=1;
    for(int i=1;i<=n;i++){
        for(int j=0;j<k;j++)pre[i][j]=pre[i-1][j];
        pre[i][i%k]+=a[i-1];
    }
    int q,l,r;
    cin>>q;
    while(q--){
        cin>>l>>r;
        bool ok=true;
        for(int i=1;i<k;i++){
            if(pre[r][i]-pre[l-1][i]!=pre[r][0]-pre[l-1][0]){
                ok=false;
                break;
            }
        }
        if(ok)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}