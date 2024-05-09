#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const double pi=3.141592653;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    double inf=1e18;
    vector<vector<double>> dp(n*2+1,vector<double> (m*2+1,inf));
    dp[0][0]=0;
    double d1=10,d2=10*pi/4;
    for(int i=0;i<2*n;i++){
        for(int j=0;j<2*m;j++){
            if(dp[i][j]==inf)continue;
            if(s[i/2][j/2]=='X'){
                if(i%2==1||j%2==1)continue;
                dp[i+2][j]=min(dp[i+2][j],dp[i][j]+d1);
                dp[i][j+2]=min(dp[i][j+2],dp[i][j]+d1);
                dp[i+2][j+2]=min(dp[i+2][j+2],dp[i][j]+2*d1);
            }else{
                if(i%2==0&&j%2==0){
                    dp[i+1][j]=min(dp[i+1][j],dp[i][j]+d1/2);
                    dp[i][j+1]=min(dp[i][j+1],dp[i][j]+d1/2);
                    dp[i+2][j]=min(dp[i+2][j],dp[i][j]+d1);
                    dp[i][j+2]=min(dp[i][j+2],dp[i][j]+d1);
                    dp[i+2][j+2]=min(dp[i+2][j+2],dp[i][j]+d1+d2);
                    dp[i+1][j+2]=min(dp[i+1][j+2],dp[i][j]+d1/2+d2);
                    dp[i+2][j+1]=min(dp[i+2][j+1],dp[i][j]+d1/2+d2);
                }else if(i%2==1&&j%2==0){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+d2);
                    dp[i+1][j+2]=min(dp[i+1][j+2],dp[i][j]+d2+d1/2);
                }else if(i%2==0&&j%2==1){
                    dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]+d2);
                    dp[i+2][j+1]=min(dp[i+2][j+1],dp[i][j]+d2+d1/2);
                }
            }
        }
    }
    for(int i=0;i<m*2;i++){
        dp[n*2][i+1]=min(dp[n*2][i+1],dp[n*2][i]+d1/2);
    }
    for(int i=0;i<n*2;i++){
        dp[i+1][m*2]=min(dp[i+1][m*2],dp[i][m*2]+d1/2);
    }
    cout<<fixed<<setprecision(8)<<dp[2*n][2*m];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}