#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
const int N=3e5+5;
vector<int> e;
int p[N],v[N];
void init(){
    e.clear();
    for(int i=0;i<N;i++)v[i]=0;
    for(int i=2;i<N;i++){
        if(!v[i])e.push_back(i);
        for(int j=0;j<e.size()&&i*e[j]<N;j++){
            v[i*e[j]]=1;
            if(i%e[j]==0)break;
        }
    }
}
void solve(){
    int n;
    cin>>n;
    int m=1;
    while(n-1>(m%2==1?m*(m+1)/2:m*(m+1)/2-m/2+1))m++;
    vector<vector<int>> g(m,vector<int>(m,1));
    if(m%2==0){
        for(int i=1;i<m-2;i+=2){
            g[i][i+1]=g[i+1][i]=0;
        }
    }
    vector<int> cur(m);
    vector<int> ans;
    auto dfs=[&](auto &&self,int x)->void{
        for(int &i=cur[x];i<m;i++){
            if(g[x][i]){
                g[x][i]=g[i][x]=0;  
                self(self,i);
            }
        }
        ans.push_back(e[x]);
    };
    dfs(dfs,0);
    for(int i=0;i<n;i++)cout<<ans[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    init();
    while(T--){
        solve();
        cout<<endl;
    }
    return 0;
}