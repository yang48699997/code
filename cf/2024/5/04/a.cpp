/*
 * Author: Ram
 * Date: 2024-05-04
 * Source: https://atcoder.jp/contests/abc352/tasks/abc352_a
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,x,y,z;
    cin>>n>>x>>y>>z;
    if((x-z)*(y-z)>0)cout<<"No";
    else cout<<"Yes";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}