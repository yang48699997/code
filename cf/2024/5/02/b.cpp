/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://codeforces.com/contest/1968/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    string s1,s2;
    cin>>n>>m>>s1>>s2;
    int l=0;
    for(int i=0;i<m&&l<n;i++){
        if(s2[i]==s1[l])l++;
    }
    cout<<l;
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