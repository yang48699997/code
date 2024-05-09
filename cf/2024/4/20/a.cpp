/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_a
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int x=0;
    for(int i=3;i<6;i++)x=x*10+(s[i]-'0');
    if(x>0&&x<350&&x!=316)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}