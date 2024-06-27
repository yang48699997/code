#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
int dir[4][2]={{1,0},{0,1},{-1,0},{0,-1}};
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int>(m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int res=-1;
            for(int k=0;k<4;k++){
                int x=i+dir[k][0];
                int y=j+dir[k][1];
                if(x>=0&&x<n&&y>=0&&y<m){
                    if(res==-1)res=a[x][y];
                    else res=max(a[x][y],res);
                }
            }
            if(a[i][j]>res)a[i][j]=res;
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cout<<a[i][j]<<" \n"[j==m-1];
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
        // cout<<endl;
    }
    return 0;
}