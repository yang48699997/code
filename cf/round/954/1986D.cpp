#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    vector<int> a(n-1);
    vector<vector<int>> dp(n,vector<int>(n,-1));
    auto dfs=[&](auto &&self,int l,int r)->int{
        if(l==r)return a[l];
        if(dp[l][r]!=-1)return dp[l][r];
        int res=1e9;
        for(int j=l;j<r;j++){
            int res1=self(self,l,j);
            int res2=self(self,j+1,r);
            res=min(res,res1+res2);
            res=min(res,res1*res2);
        }
        dp[l][r]=res;
        return res;
    };
    int ans=1e9;
    for(int i=0;i<n-1;i++){
        for(int j=0;j<=i;j++)a[j]=s[j]-'0';
        a[i]=a[i]*10+s[i+1]-'0';
        for(int j=i+2;j<n;j++)a[j-1]=s[j]-'0';
        int res=dfs(dfs,0,n-2);
        for(int j=0;j<n;j++){
            for(int k=0;k<n;k++)dp[j][k]=-1;
        }
        ans=min(ans,res);
    }
    cout<<ans;
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