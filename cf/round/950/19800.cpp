#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> cnt(7);
    for(char ch:s){
        cnt[ch-'A']++;
    }
    int ans=0;
    for(int i:cnt)ans+=max(0,m-i);
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