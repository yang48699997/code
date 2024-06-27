/*
 * Author: Ram
 * Date: 2024-05-20
 * Source: https://codeforces.com/contest/1974/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    set<char> st;
    for(auto c:s)st.insert(c);
    string res;
    for(auto it=st.begin();it!=st.end();it++){
        res+=*it;
    }
    map<char,char> mp;
    for(int i=res.length()-1;i>=0;i--)mp[res[i]]=res[res.length()-i-1];
    for(int i=0;i<n;i++)s[i]=mp[s[i]];
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