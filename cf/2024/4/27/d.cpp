/*
 * Author: Ram
 * Date: 2024-04-27
 * Source: https://codeforces.com/contest/1966/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> ans;
    int x=k-1;
    int tot=k-1,cur=k+1;
    for(int i=0;x&&i<31;i++){
        if((1<<i)>x){
            ans.push_back(x);
            break;
        }
        ans.push_back(1<<i);
        x-=(1<<i);
    }
    if(n==k)n--;
    while(tot<n){
        ans.push_back(cur);
        tot+=cur;
        if(cur+k<=n&&cur+k<=tot){
            cur=cur+k;
            while(cur<=n){
                ans.push_back(cur);
                tot+=cur;
                cur=cur*2;
            }
        }
        cur=tot+1;
    }
    cout<<ans.size()<<endl;
    for(int i:ans)cout<<i<<' ';
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