#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,k;
    cin>>n>>k;
    cout<<n*k-(k-1);
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