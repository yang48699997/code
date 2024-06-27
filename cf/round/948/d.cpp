#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<string> s(n);
    for(int i=0;i<n;i++)cin>>s[i];
    vector<string> res(m);
    map<string,int> cnt;
    int mx=-1;
    string ans;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(s[j][i]=='0')res[i]+='1';
            else res[i]+='0';
        }
        cnt[res[i]]++;
        if(cnt[res[i]]>mx){
            mx=cnt[res[i]];
            ans=res[i];
        }
    }
    cout<<mx<<endl;
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