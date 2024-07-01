#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n),w(n);
    for(int i=0;i<n;i++)cin>>a[i];
    for(int i=0;i<n;i++)cin>>w[i];
    vector<int> cnt(n+1),sum(n+1),mi(n+1);
    for(int i=0;i<n;i++){
        cnt[a[i]]++;
        sum[a[i]]+=w[i];
        mi[a[i]]=max(mi[a[i]],w[i]);
    }
    int ans=0;
    for(int i=0;i<=n;i++)ans+=sum[i]-mi[i];
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}