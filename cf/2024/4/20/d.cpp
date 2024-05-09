/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_d
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
const int N=2e5+5;
using ll = long long;
int fa[N],s[N],tot[N];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y){
        s[x]++;
        return ;
    }
    s[x]+=s[y]+1;
    tot[x]+=tot[y];
    fa[y]=x;
    return;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,s[i]=0,tot[i]=1;
    for(int i=0;i<m;i++){
        int x,y;
        cin>>x>>y;
        merge(x,y);
    }
    ll ans=0;
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        int x=find(i);
        if(v[x])continue;
        v[x]=1;
        ll p=tot[x];
        ans+=p*(p-1)/2-s[x];
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}