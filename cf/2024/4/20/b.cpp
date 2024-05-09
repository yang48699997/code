/*
 * Author: Ram
 * Date: 2024-04-20
 * Source: https://atcoder.jp/contests/abc350/tasks/abc350_b
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> cnt(n+1);
    for(int i=0;i<q;i++){
        int x;
        cin>>x;
        cnt[x]^=1;
    }
    int ans=n;
    for(int i=1;i<=n;i++){
        if(cnt[i])ans--;
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