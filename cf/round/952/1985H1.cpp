#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
const int N=1e6+5;
int fa[N],siz[N];
int find(int x){
    if(fa[x]==x)return fa[x];
    fa[x]=find(fa[x]);
    return fa[x];
}
void merge(int x,int y){
    x=find(x);
    y=find(y);
    if(x==y)return;
    siz[x]+=siz[y];
    fa[y]=x;
}
int dir[4][2]={{1,0},{-1,0},{0,1},{0,-1}};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(int i=0;i<n;i++)cin>>g[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            fa[i*m+j]=i*m+j;
            if(g[i][j]=='.')siz[i*m+j]=0;
            else siz[i*m+j]=1;
        }
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)cerr<<g[i][j]<<" \n"[j==m-1];
    // }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<m;j++)cerr<<siz[i*n+j]<<" \n"[j==m-1];
    // }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='.')continue;
            if(i-1>=0&&g[i-1][j]=='#')merge(i*m+j,i*m-m+j);
            if(j-1>=0&&g[i][j-1]=='#')merge(i*m+j,i*m-1+j);
        }
    }
    int mx=0;
    set<int> st;
    for(int i=0;i<n;i++){
        int res=0;
        st.clear();
        for(int j=0;j<m;j++){
            if(g[i][j]=='.')res++;
            st.insert(find(i*m+j));
            for(int p=0;p<4;p++){
                int x=i+dir[p][0];
                int y=j+dir[p][1];
                if(x>=0&&x<n&&y>=0&&y<m)st.insert(find(x*m+y));
            }
        }
        for(auto it:st)res+=siz[it];
        mx=max(mx,res);
    }
    for(int j=0;j<m;j++){
        int res=0;
        st.clear();
        for(int i=0;i<n;i++){
            if(g[i][j]=='.')res++;
            st.insert(find(i*m+j));
            for(int p=0;p<4;p++){
                int x=i+dir[p][0];
                int y=j+dir[p][1];
                if(x>=0&&x<n&&y>=0&&y<m)st.insert(find(x*m+y));
            }
        }
        for(auto it:st)res+=siz[it];
        mx=max(mx,res);
    }
    cout<<mx;
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