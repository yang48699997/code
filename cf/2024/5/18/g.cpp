/*
 * Author: Ram
 * Date: 2024-05-18
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
void cal(int x){
    int sum=1<<x;
    vector<vector<int>> e(1<<sum);
    int mask=1<<x;
    mask--;
    for(int i=0;i<sum;i++){
        e[i].push_back(((2*i)&mask));
        e[i].push_back(((2*i+1)&mask));
    }
    vector<vector<int>> dp(1<<sum,vector<int>(sum));
    for(int i=0;i<sum;i++)dp[1<<i][i]=1;
    for(int i=1;i<1<<sum;i++){
        for(int j=0;j<sum;j++){
            if(!dp[i][j])continue;
            for(int nxt:e[j]){
                if(i&(1<<nxt))continue;
                dp[i|(1<<nxt)][nxt]+=dp[i][j];
            }
        }
    }
    int cnt=0;
    for(int i=0;i<sum;i++)cnt+=dp[(1<<sum)-1][i];
    cnt/=pow(2,x);
    cout<<cnt<<endl;
}
using ll =long long;
const int  mod=998244353;
int powMod(ll x,int mod){
    ll res=1;
    ll y=2;
    while(x){
        if(x&1)res=res*y%mod;
        y=y*y%mod;
        x>>=1;
    }
    return res;
}
int p[33];
void solve(){
    // for(int i=1;i<=4;i++){
    //     cout<<i<<':';
    //     cal(i);
    // }
    int n;
    cin>>n;
    int mx=1;
    p[1]=2;
    p[0]=1;
    while(true){
        if(p[mx]-mx>mod)break;
        p[mx+1]=p[mx]*2;
        mx++;
    }
    int cur;
    if(n>mx){
        cur=powMod(n-1,mod-1);
        cur-=n;
        if(cur<0)cur+=mod-1;
    }
    else cur=p[n-1]-n;
    int ans=powMod(cur,mod);
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}