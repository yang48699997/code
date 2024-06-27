/*
 * Author: Ram
 * Date: 2024-05-10
 * Source: https://codeforces.com/contest/1971/problem/G
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<int,vector<int>> cnt;
    map<int,vector<int>> mp;
    for(int i=0;i<n;i++){
        int cur=a[i];
        cur>>=2;
        cur<<=2;
        cnt[cur].push_back(i);
        mp[cur].push_back(a[i]);
    }
    for(auto it=mp.begin();it!=mp.end();it++){
        int cur=it->first;
        auto &num=it->second;
        auto &v=cnt[cur];
        sort(num.begin(),num.end());
        for(int i=0;i<v.size();i++){
            a[v[i]]=num[i];
        }
    }
    for(int i=0;i<n;i++)cout<<a[i]<<' ';
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