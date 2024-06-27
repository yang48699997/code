#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int a,b;
    cin>>a>>b;
    int ans=1;
    for(int i=0;i<31;i++){
        if((a&1)==(b&1))ans*=2;
        else break;
        a>>=1;
        b>>=1;
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