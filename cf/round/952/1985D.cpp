#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> g(n);
    for(int i=0;i<n;i++)cin>>g[i];
    vector<int> cnt1(n),cnt2(m);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(g[i][j]=='#')cnt1[i]++,cnt2[j]++;
        }
    }
    int ans=-1,mx=-1;
    for(int i=0;i<n;i++){
        if(cnt1[i]>mx){
            mx=cnt1[i];
            ans=i;
        }
    }
    cout<<ans+1<<" ";
    ans=mx=-1;
    for(int i=0;i<m;i++){
        if(cnt2[i]>mx){
            mx=cnt2[i];
            ans=i;
        }
    }
    cout<<ans+1;
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