/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/K
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    if(n%4==0||n%4==1)cout<<"Fluttershy";
    else cout<<"Pinkie Pie";
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