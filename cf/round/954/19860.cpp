#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int a,b,c;
    cin>>a>>b>>c;
    int ans=1e9;
    for(int i=1;i<=10;i++){
        int res=0;
        res+=abs(i-a);
        res+=abs(i-b);
        res+=abs(i-c);
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