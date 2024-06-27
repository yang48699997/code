#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,a;
    cin>>n>>a;
    int ans=0;
    while(n--){
        int t;
        cin>>t;
        ans=max(ans,t)+a;
        cout<<ans<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}