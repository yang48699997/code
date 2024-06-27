/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: https://atcoder.jp/contests/abc353/tasks/abc353_b
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int ans=1;
    int l=k;
    for(int i=0;i<n;i++){
        if(l>=a[i]){
            l-=a[i];
        }else{
            l=k;
            l-=a[i];
            ans++;
        }
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}