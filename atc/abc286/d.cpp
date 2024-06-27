#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,tar;
    cin>>n>>tar;
    vector<int> dp(tar+1);
    dp[0]=1;
    int a,b;
    for(int i=0;i<n;i++){
        cin>>a>>b;
        while(b--){
            for(int j=tar;j-a>=0;j--)dp[j]|=dp[j-a];
        }
    }
    if(dp[tar])cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}