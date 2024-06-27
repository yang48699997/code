#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    while(n--){
        int x;
        cin>>x;
        if(x<=m)ans++;
        m-=x;
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}