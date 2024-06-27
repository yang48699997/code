#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        string s;
        cin>>s;
        for(int j=0;j<m;j++){
            if(s[j]=='o')a[i]+=1<<j;
        }
    }
    int ans=m;
    for(int i=1;i<1<<n;i++){
        int res=0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))res|=a[j];
        }
        if(res==(1<<m)-1)ans=min(ans,__builtin_popcount(i));
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