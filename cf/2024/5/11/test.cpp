/*
 * Author: Ram
 * Date: 2024-05-11
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n=100;
    int ans=0;
    for(int i=1;i<=n;i++){
        int cur=i;
        while(cur){
            int d=__builtin_ctz(cur);
            ans+=d;
            // cout<<__builtin_ctz(cur)<<' ';
            cout<<ans<<' ';
            cur-=(cur&-cur);
        }

    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}