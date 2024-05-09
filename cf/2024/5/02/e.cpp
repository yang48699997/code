/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://codeforces.com/contest/1968/problem/E
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    int cnt=1;
    cout<<1<<' '<<1<<endl;
    cout<<n<<' '<<n<<endl;
    if(n==2)return;
    cout<<2<<' '<<1<<endl;
    for(int i=3;i<n;i++){
        cout<<1<<' '<<i<<endl;
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