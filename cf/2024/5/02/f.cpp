/*
 * Author: Ram
 * Date: 2024-05-03
 * Source: https://codeforces.com/contest/1968/problem/F
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,q;
    cin>>n>>q;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    vector<int> pre(n+1);
    map<int,vector<int>> cnt;
    for(int i=1;i<=n;i++){
        pre[i]=pre[i-1]^a[i];
        cnt[pre[i]].push_back(i);
    }
    while(q--){
        int l,r;
        cin>>l>>r;
        if(pre[r]==pre[l-1]){
            cout<<"YES"<<endl;
            continue;
        }
        auto &arr=cnt[pre[r]];
        auto &arr2=cnt[pre[l-1]];
        auto it=upper_bound(arr.begin(),arr.end(),l-1);
        int x=*it;
        auto it2=upper_bound(arr2.begin(),arr2.end(),x);
        if(x==r)cout<<"NO"<<endl;
        else if(it2==arr2.end()||*it2>r)cout<<"NO"<<endl;
        else cout<<"YES"<<endl;
    }
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