/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://codeforces.com/contest/1968/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    int cur=3e5;
    cout<<cur<<' ';
    for(int i=1;i<n;i++){
        int x;
        cin>>x;
        cur+=x;
        cout<<cur<<' ';
    }
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