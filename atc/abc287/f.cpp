#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=5e3+5;
const int mod=998244353;
vector<int> e[N];
ll dp1[N][N],dp2[N][N];
ll f1[N],f2[N];
int n;
int dfs(int x,int fa){
    int p=1;
    dp2[x][1]=1;
    dp1[x][0]=1;
    for(int nxt:e[x]){
        if(nxt==fa)continue;
        int siz=dfs(nxt,x);
        for(int i=0;i<=p+siz;i++)f1[i]=f2[i]=0;
        for(int i=p;i>=0;i--){
            for(int j=0;j<=siz;j++){
                f1[i+j]+=(dp1[x][i]*(dp1[nxt][j]+dp2[nxt][j]))%mod,f1[i+j]%=mod;
                f2[i+j]+=(dp2[x][i]*dp1[nxt][j])%mod,f2[i+j]%=mod;
                if(i+j>0)f2[i+j-1]+=(dp2[x][i]*dp2[nxt][j])%mod,f2[i+j-1]%=mod;
            }
        }
        for(int i=0;i<=p+siz;i++){
            dp1[x][i]=f1[i];
            dp2[x][i]=f2[i];
        }
        p+=siz;
    }
    return p;
}
void solve(){
    cin>>n;
    for(int i=1;i<=n;i++){
        e[i].clear();
        for(int j=0;j<=n;j++)dp1[i][j]=dp2[i][j]=0;
    }
    int x,y;
    for(int i=1;i<n;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(1,-1);
    for(int i=1;i<=n;i++){
        cout<<(dp1[1][i]+dp2[1][i])%mod<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}