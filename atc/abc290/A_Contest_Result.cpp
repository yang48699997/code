#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<m;i++){
        int b;
        cin>>b;
        b--;
        ans+=a[b];
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