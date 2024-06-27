#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e5+5;
int n;
int a[10];
int dp[N];
int dfs(int x){
    if(x<0)return 0;
    if(dp[x]!=-1)return dp[x];
    int res=0;
    for(int i=0;i<n;i++){
        res|=dfs(x-a[i]);
    }
    dp[x]=res;
    return res;
}
void solve(){
    cin>>n;
    for(int i=0;i<n;i++)cin>>a[i];
    int m;
    cin>>m;
    dp[0]=1;
    for(int i=1;i<N;i++)dp[i]=-1;
    int x;
    while(m--){
        cin>>x;
        dp[x]=0;
    }
    cin>>x;
    if(dfs(x))cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}