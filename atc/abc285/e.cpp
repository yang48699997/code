#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<ll> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)a[i]+=a[i-1];
    vector<ll> f(n+1);
    for(int i=1;i<=n;i++){
        f[i]=a[(i-1)/2]*2;
        if(i%2==0){
            f[i]+=a[i/2]-a[i/2-1];
        }
    }
    vector<ll> dp(n+1);
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            dp[j]=max(dp[j],dp[j-i]+f[i]);
        }
    }
    cout<<dp[n];
}


int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}