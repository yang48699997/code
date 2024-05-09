#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int r=n;
    while(r){
        int val=(n-1)/r+1;
        int l=(n-1)/val+1;
        cout<<l<<' '<<val<<endl;
        r=l-1;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}