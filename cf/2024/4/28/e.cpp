/*
 * Author: Ram
 * Date: 2024-04-28
 * Source: https://codeforces.com/contest/1966/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int cur=0,mx=0,mi=0;
    for(char c:s){
        if((cur&1)&&c=='1')cur++;
        else if(!(cur&1)&&c=='0')cur++;
        else cur--;
        mi=min(mi,cur);
        mx=max(mx,cur);
    }
    cout<<mx-mi;
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