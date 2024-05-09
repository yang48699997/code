/*
 * Author: Ram
 * Date: 2024-04-30
 * Source: https://codeforces.com/contest/1972/problem/D1
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int gcd(int x,int y){
    while(y){
        int temp=y;
        y=x%y;
        x=temp;
    }
    return x;
}
using ll = long long;
int T;
void solve(){
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(ll i=1;i<=m;i++){
        for(ll j=i;j<=n;j+=i){
            if((i*gcd(i,j))%(i+j)==0)ans++;
        }
    }
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