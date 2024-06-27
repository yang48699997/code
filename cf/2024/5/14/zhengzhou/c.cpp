/*
 * Author: Ram
 * Date: 2024-05-16
 * Source: 
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    vector<int> d(n+1);
    vector<int> v(n+1);
    for(int i=0;i<n;i++)d[a[i]]=i;
    int tot=0;
    vector<vector<int>> cnt(n);
    vector<int> dp;
    int ans=0;
    for(int i=0;i<n;){
        int j=i;
        int tar=d[a[i]];
        tot++;
        while(j<=tar){
            if(!v[a[j]])cnt[tot-1].push_back(a[j]);
            v[a[j]]=1;
            tar=max(tar,d[a[j]]);
            j++;
        }
        i=j;
    }
    for(int i=0;i<tot;i++){
        sort(cnt[i].rbegin(),cnt[i].rend());
        ans+=cnt[i].size();
        for(int x:cnt[i]){
            auto it=upper_bound(dp.begin(),dp.end(),x);
            if(it==dp.end())dp.push_back(x);
            else *it=min(*it,x);
        }
    }
    ans-=dp.size();
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}