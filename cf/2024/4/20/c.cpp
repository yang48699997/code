/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_c
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    int cnt=0;
    vector<pair<int,int>> ans(n);
    for(int i=1;i<=n;i++){
        while(a[i]!=i){
            ans[cnt++]={min(i,a[i]),max(i,a[i])};
            swap(a[i],a[a[i]]);
        }
    }
    cout<<cnt<<endl;
    for(int i=0;i<cnt;i++){
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}