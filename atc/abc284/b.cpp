#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,x;
    cin>>n;
    int ans=0;
    while(n--){
        cin>>x;
        if(x%2==1)ans++;
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