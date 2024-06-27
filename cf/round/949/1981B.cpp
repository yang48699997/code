#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    int ans=n;
    for(int i=0;i<31;i++){
        if(ans&(1<<i))continue;
        int cur=1<<i;
        for(int j=30;j>=0;j--){
            if((cur|(1<<j))<=n)cur|=1<<j;
        }
        int dif=abs(n-cur);
        if(dif<=m)ans|=1<<i;
        else{
            cur=(n>>i)<<i;
            cur+=1<<i;
            if(cur-n<=m)ans|=1<<i;
        }
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