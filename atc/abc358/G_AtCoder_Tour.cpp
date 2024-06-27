#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void solve(){
    int h,c,k;
    cin>>h>>c>>k;
    int x,y;
    cin>>x>>y;
    x--;
    y--;
    vector<vector<int>> a(h,vector<int>(c));
    for(int i=0;i<h;i++){
        for(int j=0;j<c;j++)cin>>a[i][j];
    }
    vector<vector<ll>> dp(h,vector<ll>(c,-1e18));
    vector<vector<ll>> temp(h,vector<ll>(c,-1e18));
    int mx=h*c;
    dp[x][y]=0;
    for(int t=0;t<min(k,mx);t++){
        for(int i=0;i<h;i++){
            for(int j=0;j<c;j++){
                temp[i][j]=dp[i][j]+a[i][j];
                for(int p=0;p<4;p++){
                    x=i+dir[p][0];
                    y=j+dir[p][1];
                    if(x>=0&&x<h&&y>=0&&y<c){
                        temp[i][j]=max(temp[i][j],dp[x][y]+a[i][j]);
                    }
                }
            }
        }
        dp=temp;
    }
    ll ans=0;
    ll dif=k-min(k,mx);
    for(int i=0;i<h;i++){
        for(int j=0;j<c;j++){
            ans=max(ans,dp[i][j]+dif*a[i][j]);
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