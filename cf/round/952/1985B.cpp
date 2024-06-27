#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    int ans=2,mx=0;
    for(int i=2;i<=n;i++){
        int res=0;
        for(int j=i;j<=n;j+=i)res+=j;
        if(res>mx){
            ans=i;
            mx=res;
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