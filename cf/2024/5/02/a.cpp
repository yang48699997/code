/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://codeforces.com/contest/1968/problem/0
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
int T;
void solve(){
    int x;
    cin>>x;
    int ans=0,res=0;
    for(int i=1;i<x;i++){
        if(gcd(i,x)+i>res){
            res=gcd(i,x)+i;
            ans=i;
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