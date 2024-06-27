/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    string s;
    cin>>s;
    int ans=1;
    int cur=1,n=s.length();
    while(cur<n){
        if(s[cur]!=s[cur-1])ans++;
        cur++;
    }
    if(s[0]=='0'&&ans>1)ans--;
    else if(s[0]=='1'&&ans>2)ans--;
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