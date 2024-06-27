#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<string> s(k);
    for(int i=0;i<k;i++)cin>>s[i];
    string ss;
    for(int i=k;i<n;i++)cin>>ss;
    sort(s.begin(),s.end());
    for(auto &p:s)cout<<p<<endl;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}