#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    int ans=0;
    for(int i=0;i<n&&k;i++){
        if(a[i]>ans)break;
        else if(a[i]==ans){
            k--;
            ans++;
        }
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