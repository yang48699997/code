/*
 * Author: Ram
 * Date: 2024-05-17
 * Source: https://codeforces.com/contest/1973/problem/D
*/
#include <bits/stdc++.h>
using namespace std;


int T;
void solve(){
    int n,k;
    cin>>n>>k;
    int mx,ans;
    int cur=n;
    while(true){
        cout<<"? 1 "<<cur<<endl;
        cin>>ans;
        if(ans==n){
            mx=cur/n;
            break;
        }else cur+=n;
    }
    for(int i=1;i<=n/k;i++){
        int pre=1;
        int now=i*mx;
        int j=1;
        for(;j<=k;j++){
            cout<<"? "<<pre<<' '<<now<<endl;
            cin>>ans;
            if(ans==n+1)break;
            else pre=ans+1;
            if(pre>n)break;
        }
        if(j==k&&pre==n+1){
            cout<<"! "<<now<<endl;
            cin>>ans;
            return;
        }
    }
    cout<<"! -1"<<endl;
    cin>>ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}