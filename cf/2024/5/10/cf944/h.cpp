/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/H
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=1e4+5;
vector<int> e[N];
int dfn[N],low[N];
int stk[N],instk[N];
int scc[N],siz[N];
int top,tot,cnt;
int T;
void tarjan(int x){
    dfn[x]=low[x]=++tot;
    stk[top++]=x;
    instk[x]=1;
    for(int nxt:e[x]){
        if(!dfn[nxt])tarjan(nxt),low[x]=min(low[x],low[nxt]);
        else if(instk[nxt])low[x]=min(low[x],dfn[nxt]);
    }
    if(dfn[x]!=low[x])return;
    scc[x]=++cnt;
    int y=0;
    while(y!=x){
        y=stk[--top];
        instk[y]=0;
        scc[y]=cnt;
        siz[cnt]++;
    }
}
void solve(){
    int n;
    cin>>n;
    vector<vector<int>> a(3,vector<int> (n));
    for(int i=0;i<3;i++){
        for(int j=0;j<n;j++)cin>>a[i][j];
    }
    for(int i=1;i<=n*2;i++){
        e[i].clear();
        dfn[i]=low[i]=0;
        scc[i]=siz[i]=0;
        instk[i]=0;
    }
    tot=top=cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<3;j++){
            swap(a[0][i],a[j][i]);
            int x=a[0][i],y=a[1][i],z=a[2][i];
            if(x>0){
                if(y>0)e[x+n].push_back(y);
                else e[x+n].push_back(-y+n);
                if(z>0)e[x+n].push_back(z);
                else e[x+n].push_back(-z+n);
            }else{
                if(y>0)e[-x].push_back(y);
                else e[-x].push_back(-y+n);
                if(z>0)e[-x].push_back(z);
                else e[-x].push_back(-z+n);
            }
        }
    }
    for(int i=1;i<=n*2;i++){
        if(!dfn[i])tarjan(i);
    }
    for(int i=1;i<=n;i++){
        if(scc[i]==scc[i+n]){
            cout<<"NO";
            return ;
        }
    }
    cout<<"YES";
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