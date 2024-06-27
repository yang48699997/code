#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll =long long;
void solve(){
    string s;
    cin>>s;
    ll ans=0;
    for(int i=0;i<s.length();i++){
        ans=ans*26+s[i]-'A'+1;
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