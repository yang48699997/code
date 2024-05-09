/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
vector<int> e[N];
int fa[N][32];
int v[N],d[N];
int d_max=0;
int tlz(int x){
    int ans=0;
    while(x){
        if(x&1)return ans;
        x>>=1;
        ans++;
    }
    return ans;
}
void dfs(int x,int f,int dis){
    v[x]=1;
    d[x]=dis;
    fa[x][0]=f;
    for(int nxt:e[x]){
        if(v[nxt])continue;
        dfs(nxt,x,dis+1);
    }
}  
int get_anc(int x,int k){
    for(;k;k&=(k-1)){
        x=fa[x][tlz(k)];
    }
    return x;
}
int lca(int x,int y){
    if(d[x]>d[y])swap(x,y);
    y=get_anc(y,d[y]-d[x]);
    if(y==x)return x;
    for(int i=31;i>=0;i--){
        int px=fa[x][i];
        int py=fa[y][i];
        if(px!=py)x=px,y=py;
    }
    return fa[x][0];
}
int get_dis(int x,int y){
    int f=lca(x,y);
    return d[x]+d[y]-d[f]*2;
}
void solve(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)e[i].clear(),v[i]=0;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int r,t;
    cin>>r>>t;
    dfs(r,-1,0);
    for(int i=1;i<32;i++){
        for(int j=1;j<=n;j++){
            int f=fa[j][i-1];
            if(f==-1){
                fa[j][i]=-1;
                continue;
            }
            fa[j][i]=fa[f][i-1];
        }
    }
    vector<int> vv(n+1),dd(n+1);
    int x=r,y=r;
    dd[0]=0;
    queue<int> q;
    q.push(r);
    vv[r]=1;
    for(int i=1;i<=n;i++){
        queue<int> q2;
        while(!q.empty()){
            int xx=q.front();
            q.pop();
            for(int nxt:e[xx]){
                if(vv[nxt])continue;
                vv[nxt]=1;
                int d1=get_dis(x,y);
                int d2=get_dis(x,nxt);
                int d3=get_dis(nxt,y);
                int res=max(d1,max(d2,d3));
                if(d2==res){
                    y=nxt;
                }else if(d3==res){
                    x=nxt;
                }
                q2.push(nxt);
            }
        }
        // cout<<x<<' '<<y<<endl;
        q=q2;
        dd[i]=(get_dis(x,y)+1)/2;
    }
    int l=n+t;
    for(int i=1;i<=n;i++){
        int tar=min(l,n);
        while((l-t)*i>=dd[tar])l--,tar=min(l,n);
        cout<<l+1<<' ';
    }
    // cout<<endl;
    // for(int i=0;i<=n;i++)cout<<i<<' '<<dd[i]<<endl;
    // cout<<"__________________";
    // for(int i=0;i<=n;i++)cout<<fa[i][0]<<endl;
    // cout<<get_dis(1,3);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}