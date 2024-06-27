#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int l,r;
    cin>>l>>r;
    int cnt=0;
    int cur=1;
    while(cur<=r){
        cur*=2;
        cnt++;
    }
    cout<<cnt-1;
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