/*
 * Author: Ram
 * Date: 2024-05-17
 * Source: https://codeforces.com/contest/1973/problem/C
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
    bool ok=false;
    for(int i=1;i<n-1;i+=2){
        if(a[i]==1){
            ok=true;
            break;
        }
    }
    vector<int> d(n+1);
    if(ok){
        vector<int> b;
        for(int i=2;i<n;i+=2)b.push_back(a[i]);
        sort(b.begin(),b.end());
        int l=1,r=n;
        for(int i:b)d[i]=r--;
        b.clear();
        for(int i=1;i<n;i+=2)b.push_back(a[i]);
        sort(b.rbegin(),b.rend());
        for(int i:b)d[i]=l++;
        d[a[0]]=l++;
        for(int i:a)cout<<d[i]<<' ';
    }else{
        vector<int> b;
        for(int i=1;i<n-1;i+=2)b.push_back(a[i]);
        sort(b.begin(),b.end());
        int l=1,r=n;
        for(int i:b)d[i]=r--;
        b.clear();
        for(int i=0;i<n-1;i+=2)b.push_back(a[i]);
        sort(b.rbegin(),b.rend());
        for(int i:b)d[i]=l++;
        d[a[n-1]]=l++;
        for(int i:a)cout<<d[i]<<' ';
    }
    // int cnt=0;
    // for(int i=1;i<n-1;i+=2){
    //     if(d[a[i]]+a[i]>d[a[i-1]]+a[i-1]&&d[a[i]]+a[i]>d[a[i+1]]+a[i+1])cnt++;
    // }
    // cout<<endl<<cnt;
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