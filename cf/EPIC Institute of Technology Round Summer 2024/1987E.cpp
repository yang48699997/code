#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
const int N=5e3+5;
vector<int> e[N];
ll a[N],sum[N];
int d[N],mxd[N];
int n;
ll dp[N][N];
ll ans;
ll inf=1e18;
void dfs(int x,int fa){
    int cnt=0;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        d[nxt]=d[x]+1;
        cnt++;
        dfs(nxt,x);
        sum[x]+=a[nxt];
        for(int j=0;j<n;j++){
            dp[x][j+1]=min(inf,dp[nxt][j]+dp[x][j+1]);
        }
    }
    if(cnt==0){
        mxd[x]=d[x];
        dp[x][0]=inf;
    }else{
        if(a[x]>sum[x]){
            ll dif=a[x]-sum[x];
            for(int j=0;j<n&&dif;j++){
                ll cur=min(dif,dp[x][j]);
                dif-=cur;
                dp[x][j]-=cur;
                ans+=cur*j;
            }
        }else{
            ll dif=sum[x]-a[x];
            dp[x][0]=min(inf,dp[x][0]+dif);
        }
    }
}

void solve(){
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum[i]=0;
        d[i]=mxd[i]=0;
        e[i].clear();
    }    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)dp[i][j]=0;
    }
    for(int i=1;i<n;i++){
        int f;
        cin>>f;
        f--;
        e[f].push_back(i);
        e[i].push_back(f);
    }
    d[0]=1;
    ans=0;
    dfs(0,-1);
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