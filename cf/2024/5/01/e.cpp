/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://atcoder.jp/contests/abc344/tasks/abc344_f
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<vector<int>> p(n+1,vector<int>(n+1)),d(n+1,vector<int>(n+1)),r(n+1,vector<int>(n+1));
    for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)cin>>p[i][j];
    for(int i=1;i<=n;i++)for(int j=1;j<n;j++)cin>>r[i][j];
    for(int i=1;i<n;i++)for(int j=1;j<=n;j++)cin>>d[i][j];
    ll inf=1e18;
    vector<vector<ll>> dp(n+1,vector<ll> (n+1,inf));
    vector<vector<ll>> dist(n+1,vector<ll> (n+1,inf));
    vector<vector<ll>> l(n+1,vector<ll> (n+1));
    dp[1][1]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            ll c=p[i][j];
            for(int ii=i;ii<=n;ii++){
                for(int jj=j;jj<=n;jj++){
                    dist[ii][jj]=inf;
                }
            }
            dist[i][j]=0;
            for(int ii=i;ii<=n;ii++){
                for(int jj=j;jj<=n;jj++){
                    if(ii+1<=n)dist[ii+1][jj]=min(dist[ii+1][jj],dist[ii][jj]+d[ii][jj]);
                    if(jj+1<=n)dist[ii][jj+1]=min(dist[ii][jj+1],dist[ii][jj]+r[ii][jj]);
                }
            }
            for(int ii=i;ii<=n;ii++){
                for(int jj=j;jj<=n;jj++){
                    ll cnt=max(0LL,(dist[ii][jj]-1-l[i][j])/c+1);
                    if(dp[ii][jj]>dp[i][j]+cnt){
                        dp[ii][jj]=dp[i][j]+cnt;
                        l[ii][jj]=l[i][j]+cnt*c-dist[ii][jj];
                    }else if(dp[ii][jj]==dp[i][j]+cnt){
                        l[ii][jj]=max(l[ii][jj],l[i][j]+cnt*c-dist[ii][jj]);
                    }
                }
            }
        }
    }
    cout<<dp[n][n]+n*2-2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}