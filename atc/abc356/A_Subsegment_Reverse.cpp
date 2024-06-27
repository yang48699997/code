#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,l,r;
    cin>>n>>l>>r;
    for(int i=1;i<l;i++)cout<<i<<" ";
    for(int i=r;i>=l;i--)cout<<i<<" ";
    for(int i=r+1;i<=n;i++)cout<<i<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}