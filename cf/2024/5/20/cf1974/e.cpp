    /*
    * Author: Ram
    * Date: 2024-05-20
    * Source: https://codeforces.com/contest/1974/problem/E
    */
    #include <bits/stdc++.h>
    using namespace std;
    using ll = long long;
    #define endl '\n'
    int T;
    void solve(){
        ll n,x;
        cin>>n>>x;
        vector<ll> c(n+1),h(n+1);
        int N=1;
        for(int i=1;i<=n;i++)cin>>c[i]>>h[i],N+=h[i];
        vector<vector<ll>> dp(n+1,vector<ll>(N,-1e18));
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=0;j<N;j++){
                if(dp[i][j]>=0)dp[i][j]+=x;
                if(dp[i-1][j]>=0){
                    if(j+h[i]<N&&dp[i-1][j]>=c[i])dp[i][j+h[i]]=dp[i-1][j]-c[i];
                    dp[i][j]=max(dp[i-1][j]+x,dp[i][j]); 
                }
            }
        }
        int ans=0;
        for(int i=1;i<N;i++)if(dp[n][i]>=0)ans=i;
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