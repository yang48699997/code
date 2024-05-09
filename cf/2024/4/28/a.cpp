/*
 * Author: Ram
 * Date: 2024-04-28
 * Source: https://codeforces.com/contest/1937/problem/A
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    int ans=1;
    while(ans*2<=n)ans*=2;
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