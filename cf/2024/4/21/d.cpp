/*
 * Author: Ram
 * Date: 2024-04-21
 * Source: https://codeforces.com/contest/1957/problem/D
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
using ll = long long;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];

    vector<vector<pair<int,int>>> l(n+1,vector<pair<int,int>>(31));
    int cur=0;    
    for(int j=0;j<31;j++)l[0][j].second=1;
    for(int i=1;i<=n;i++){
        cur^=a[i-1];
        for(int j=0;j<31;j++){
            l[i][j].first=l[i-1][j].first;
            l[i][j].second=l[i-1][j].second;
            if(cur&(1<<j))l[i][j].first++;
            else l[i][j].second++;
        }
    }
    ll ans=0;
    for(int i=0;i<n;i++){
        int res=0;
        for(int j=0;j<31;j++){
            if(a[i]&(1<<j))res=j;
        }
        ll x1=l[n][res].first-l[i][res].first;
        ll x2=l[i][res].first;
        ll y1=l[n][res].second-l[i][res].second;
        ll y2=l[i][res].second;
        ans+=x1*x2+y1*y2;
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