/*
 * Author: Ram
 * Date: 2024-04-29
 * Source: https://codeforces.com/contest/1969/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
int T;

void solve(){
    int n,k;
    cin>>n>>k;
    vector<pair<int,int>> a(n);
    for(int i=0;i<n;i++)cin>>a[i].second;
    for(int i=0;i<n;i++)cin>>a[i].first;
    sort(a.rbegin(),a.rend());
    priority_queue<int> q;
    ll ans=0;
    ll cur=0;
    for(int i=0;i<k;i++){
        cur+=a[i].second;
        q.push(a[i].second);
    }
    vector<ll> suf(n+1);
    for(int i=n-1;i>=0;i--){
        suf[i]=suf[i+1];
        if(a[i].first-a[i].second>0)suf[i]+=a[i].first-a[i].second;
    }
    ans=max(ans,suf[k]-cur);
    for(int i=k;i<n;i++){
        int x=a[i].second;
        if(!q.empty()&&x<q.top()){
            cur-=q.top();
            q.pop();
            q.push(x);
            cur+=x;
        }
        ans=max(ans,suf[i+1]-cur);
    }
    cout<<ans;
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