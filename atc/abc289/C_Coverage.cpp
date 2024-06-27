#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> c(m);
    for(int i=0;i<m;i++){
        int cc,x;
        cin>>cc;
        int res=0;
        while(cc--){
            cin>>x;
            x--;
            res|=1<<x;
        }
        c[i]=res;
    }
    vector<int> dp(1<<n);
    dp[0]=1;
    for(int i=0;i<m;i++){
        int cur=c[i];
        for(int j=(1<<n)-1;j>=0;j--)dp[cur|j]+=dp[j];
    }
    cout<<dp[(1<<n)-1];
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}