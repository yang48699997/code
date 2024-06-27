#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n*2);
    vector<vector<int>> e(n+1);
    for(int i=0;i<n*2;i++){
        cin>>a[i];
        e[a[i]].push_back(i);
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        int l=e[i][0],r=e[i][1];
        if(l==r-2)ans++;
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