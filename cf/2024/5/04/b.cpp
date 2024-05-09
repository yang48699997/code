/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_b
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s,t;
    cin>>s>>t;
    int n=s.length();
    int l=0;
    for(int i=0;i<t.length()&&l<n;i++){
        if(t[i]==s[l]){
            cout<<i+1<<' ';
            l++;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}