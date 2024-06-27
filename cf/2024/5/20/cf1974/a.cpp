/*
 * Author: Ram
 * Date: 2024-05-20
 * Source: https://codeforces.com/contest/1974/problem/0
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int x,y;
    cin>>x>>y;
    int res=y/2;
    if(y-y/2*2){
        res++;
    }
    x-=res*15-y*4;
    if(x>0)res+=(x-1)/15+1;
    cout<<res;
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