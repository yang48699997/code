#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    for(int i=n-1;i>=0;i--)cout<<s[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}