/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
using ll = long long;
ll p=123456789;
void solve(){
    ll n,d;
    cin>>n>>d;
    ll cur=(p*10+d);
    ll pp=1;
    while(pp<n){
        cur*=10;
        pp*=10;
    }
    cout<<(cur-1)/n+1;
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