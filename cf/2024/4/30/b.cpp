/*
 * Author: Ram
 * Date: 2024-04-30
 * Source: https://codeforces.com/contest/1972/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    string s;
    cin>>n>>s;
    int cnt=0;
    for(char c:s)if(c=='U')cnt++;
    if(cnt%2==1)cout<<"YES";
    else cout<<"NO";
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