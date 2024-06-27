#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2005;
const int inf=1e8;
vector<int> e[N];
int c[N];
int T;

void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>c[i],e[i].clear();
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    dp[1][n]=0;
    queue<pair<int,int>> q;
    q.emplace(1,n);
    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int nx:e[x]){
            for(int ny:e[y]){
                if(c[nx]==c[ny]||dp[nx][ny]!=-1)continue;
                dp[nx][ny]=dp[x][y]+1;
                q.emplace(nx,ny);
            }
        }
    }
    cout<<dp[n][1];
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