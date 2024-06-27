/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_a
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int i=1;
    for(;i<n;i++)if(a[i]>a[0])break;
    if(i==n)cout<<-1;
    else cout<<i+1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}