/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/0
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int x,y;
    cin>>x>>y;
    cout<<min(x,y)<<' '<<max(x,y);
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