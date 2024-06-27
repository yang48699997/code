/*
 * Author: Ram
 * Date: 2024-05-14
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)cin>>a[i];
    a[0]=0;
    int ans=0;
    ll sum=0;
    deque<int> dq;
    dq.push_back(0);
    for(int i=1;i<=n;i++){
        while(a[i]<=a[dq.back()])dq.pop_back();
        dq.push_back(i);
    }
    int pre=0;
    ll left=0;
    dq.pop_front();
    while(!dq.empty()){
        int cur=dq.front();
        dq.pop_front();
        left+=cur-pre;
        ans+=(left/a[cur]);
        left-=left/a[cur]*a[cur];
        pre=cur;
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