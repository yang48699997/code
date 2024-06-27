#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void dfs(int i,int j,int n,vector<vector<char>>& res){
    if(n==0){
        res[i][j]=='.';
        return;
    }
    int sum=1;
    for(int ii=0;ii<n-1;ii++)sum*=3;
    for(int ii=0;ii<sum;ii++){
        for(int jj=0;jj<sum;jj++){
            res[i+ii+sum][j+jj+sum]='.';
        }
    }
    dfs(i,j,n-1,res);
    dfs(i,j+sum,n-1,res);
    dfs(i,j+sum*2,n-1,res);
    dfs(i+sum*1,j,n-1,res);
    dfs(i+sum*1,j+sum*2,n-1,res);
    dfs(i+sum*2,j+sum*0,n-1,res);
    dfs(i+sum*2,j+sum*1,n-1,res);
    dfs(i+sum*2,j+sum*2,n-1,res);
}
void solve(){
    int n;
    cin>>n;
    int sum=1;
    for(int i=0;i<n;i++)sum*=3;
    vector<vector<char>> res(sum,vector<char> (sum,'#'));
    dfs(0,0,n,res);
    for(int i=0;i<sum;i++){
        for(int j=0;j<sum;j++){
            cout<<res[i][j];
        }
        cout<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}