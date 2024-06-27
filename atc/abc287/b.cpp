#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    int ans=0;
    vector<string> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    set<string> st;
    string s;
    for(int i=0;i<m;i++){
        cin>>s;
        st.insert(s);
    }
    for(auto &ss:a){
        if(st.count(ss.substr(3,3)))ans++;
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