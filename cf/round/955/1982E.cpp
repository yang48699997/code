#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod=1e9+7;

#define endl '\n'
const int mx_len=65;

int dp[mx_len][mx_len];
int T;
int k;
string n;
int dfs(int i,int is_limit,int pre){
    if(pre>k)return 0;
    if(i==60)return 1;
    if(dp[i][pre]!=-1&&!is_limit)return dp[i][pre];
    int mx=1;
    int res=0;
    if(is_limit){
        mx=n[i]-'0';
    }
    for(int j=0;j<=mx;j++){
        res=(res+dfs(i+1,is_limit&&(j==mx),pre+j))%mod;
    }
    if(!is_limit)dp[i][pre]=res;
    return res;
}
void solve(){
    ll m;
    cin>>m>>k;
    n="";
    int cnt=0;
    for(int i=0;i<m;i++){
        int t=__builtin_popcount(i);
        if(t<=k)cnt++;
    }
    while(m){
        n+='0'+m%2;
        m/=2;
    }
    while(n.size()<60)n+='0';
    reverse(n.begin(),n.end());
    cerr<<n<<endl;
    for(int i=0;i<60;i++){
        for(int j=0;j<60;j++)dp[i][j]=-1;
    }
    cout<<dfs(0,1,0)<<' '<<cnt;
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