/*
 * Author: Ram
 * Date: 2024-04-27
 * Source: https://codeforces.com/contest/1966/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a.begin(),a.end());
    vector<int> b;
    b.push_back(0);
    for(int i=0;i<n;i++){
        if(a[i]==b.back())continue;
        b.push_back(a[i]);
    }
    int m=b.size();
    bool key=true;
    for(int i=m-2;i>0;i--){
        if(b[i]-b[i-1]==1)key=!key;
        else key=true;
    }
    if(!key)cout<<"Bob";
    else cout<<"Alice";
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