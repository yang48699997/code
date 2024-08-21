#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> cnt(n+1);
    for(int i:a)cnt[i]++;
    vector<int> p;
    for(int i=0;i<=n;i++){
        if(cnt[i]==0)continue;
        p.push_back(cnt[i]);
    }
    int m=p.size();
    int inf=1e9;
    vector<int> dp(n+1);
    dp[0]=0;
    int ans=0;
    for(int i=0;i<m;i++){
        int c=p[i];
        int l=n;
        for(int j=n-c;j>=0;j--){
            if(j+c<=i+1-(dp[j]+1))dp[j+c]=max(dp[j+c],dp[j]+1);
        }
        for(int j=1;j<=n;j++){
            dp[j]=max(dp[j],dp[j-1]);
            ans=max(dp[j],ans);
        }
    }
    ans=m-ans;
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