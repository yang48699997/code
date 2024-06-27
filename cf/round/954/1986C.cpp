#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    string s;
    cin>>s;
    vector<int> a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    string c;
    cin>>c;
    sort(a.begin(),a.end());
    sort(c.begin(),c.end());
    int k=unique(a.begin(),a.end())-a.begin();
    a.resize(k);
    for(int i=0;i<k;i++)s[a[i]-1]=c[i];
    cout<<s;
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