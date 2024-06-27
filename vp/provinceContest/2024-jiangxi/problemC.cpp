#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,s;
    cin>>n>>s;
    vector<int> a(n);
    int tot=0;
    for(int i=0;i<n;i++)cin>>a[i],tot+=a[i];
    if(tot==s)cout<<n;
    else cout<<n-1;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}