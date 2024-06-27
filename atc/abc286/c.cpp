#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
ll a,b;
int n;
ll check(string s){
    ll res=0;
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1])res+=b;
    }
    return res;
}
void solve(){
    cin>>n>>a>>b;
    string s;
    cin>>s;
    ll ans=1e18;
    for(int i=0;i<n;i++){
        ans=min(ans,check(s.substr(i,n-i)+s.substr(0,i))+a*i);
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