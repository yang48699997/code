#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<ll> a(n),b(m);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<m;i++)cin>>b[i];
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    int l=0;
    int cnt=0;
    ll ans=0;
    while(l<n&&cnt<m){
        if(a[l]<b[cnt]){
            l++;
            continue;
        }
        ans+=a[l];
        l++;
        cnt++;
    }
    if(cnt!=m)cout<<-1;
    else cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}