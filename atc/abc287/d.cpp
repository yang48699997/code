#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s,t;
    cin>>t>>s;
    int n=t.length();
    int m=s.length();
    vector<int> pre(n+1),suf(n+1);
    pre[0]=1;
    suf[0]=1;
    for(int i=0;i<m;i++){
        if(t[i]=='?'||s[i]=='?'||t[i]==s[i]){
            pre[i+1]=1;
        }else break;
    }
    for(int i=1;i<=m;i++){
        if(s[m-i]=='?'||t[n-i]=='?'||s[m-i]==t[n-i]){
            suf[i]=1;
        }else break;
    }
    for(int i=0;i<=m;i++){
        // cout<<pre[i]<<' ?'<<suf[i]<<endl;
        if(pre[i]&suf[m-i])cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}