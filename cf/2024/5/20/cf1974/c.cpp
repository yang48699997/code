/*
 * Author: Ram
 * Date: 2024-05-20
 * Source: https://codeforces.com/contest/1974/problem/C
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    map<pair<int,int>,ll> cnt1,cnt2,cnt3;
    map<tuple<int,int,int>,ll> cnt;
    ll ans=0;
    for(int i=0;i<n-2;i++){
        pair<int,int> p1=make_pair(a[i],a[i+1]);  
        pair<int,int> p2=make_pair(a[i+1],a[i+2]);  
        pair<int,int> p3=make_pair(a[i],a[i+2]);
        tuple<int,int,int> tp=make_tuple(a[i],a[i+1],a[i+2]);
        ans+=cnt1[p1]+cnt2[p2]+cnt3[p3];
        ans-=cnt[tp]*3;
        cnt1[p1]++;  
        cnt2[p2]++;  
        cnt3[p3]++;  
        cnt[tp]++;
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