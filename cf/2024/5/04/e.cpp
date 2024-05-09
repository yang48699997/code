/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_e
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=2e5+5;
int fa[N],sz[N];
ll g[N];
int find(int x){
    if(fa[x]==x)return x;
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y,int i){
    x=find(x);
    y=find(y);
    if(x==y)return ;
    g[x]+=g[y]+i;
    sz[x]+=sz[y];
    fa[y]=x;
}
void solve(){
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)fa[i]=i,sz[i]=1,g[i]=0;
    vector<vector<int>> v(m);
    vector<int> c(m);
    for(int i=0;i<m;i++){
        int k,y;
        cin>>k;
        cin>>c[i];
        for(int j=0;j<k;j++){
            cin>>y;
            v[i].push_back(y);
        }
    }
    vector<int> nums(m);
    for(int i=0;i<m;i++)nums[i]=i;
    sort(nums.begin(),nums.end(),[&](int a,int b){
        return c[a]<c[b];
    });
    for(int i:nums){
        for(int j=1;j<v[i].size();j++){
            merge(v[i][0],v[i][j],c[i]);
        }
    }
    if(sz[find(1)]!=n)cout<<"-1";
    else cout<<g[fa[1]];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}