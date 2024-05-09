/*
 * Author: Ram
 * Date: 2024-05-08
 * Source: https://codeforces.com/gym/105143/problem/B
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    int n;
    cin>>n;
    int x;
    ll sum=0;
    for(int i=0;i<n;i++){
        cin>>x;
        sum+=x;
    }
    int ans=1<<30;
    ans--;
    ans+=1<<30;
    for(int i=30;i>=0;i--){
        ans-=1<<i;
        ll cur=sum;
        for(int j=30;j>=0;j--){
            int p=1<<j;
            if((p&ans)==0)continue;
            cur-=min((ll)n,cur/p)*p;
        }
        if(cur!=0)ans+=1<<i;
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