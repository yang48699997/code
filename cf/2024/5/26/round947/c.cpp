#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=0;
    for(int i=0;i<n-1;i++){
        ans=max(ans,min(a[i],a[i+1]));
    }
    vector<int> b(3);
    for(int i=0;i<n-2;i++){
        for(int j=0;j<3;j++)b[j]=a[i+j];
        sort(b.begin(),b.end());
        ans=max(ans,b[1]);
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