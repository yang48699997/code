/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    string s;
    cin>>s;
    int n=s.length();
    char a=s[0];
    int i=1;
    for(;i<n;i++){
        if(s[i]!=a)break;
    }
    if(i==n)cout<<"NO";
    else swap(s[0],s[i]),cout<<"YES"<<endl<<s;;
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