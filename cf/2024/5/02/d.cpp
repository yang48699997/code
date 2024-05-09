/*
 * Author: Ram
 * Date: 2024-05-02
 * Source: https://codeforces.com/contest/1968/problem/D
*/
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define endl '\n'
const int N=2e5+5;
int n,k;
ll p[N],a[N];
ll f(int pp){
    ll ans=0;
    ll res=0,mx=0;
    for(int i=1;i<=min(n,k);i++){
        mx=max(mx,a[pp]);
        res+=a[pp];
        ans=max(ans,res+(k-i)*mx);
        pp=p[pp];
    }
    return ans;
}
int T;
void solve(){
    int p1,p2;
    cin>>n>>k>>p1>>p2;
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int i=1;i<=n;i++)cin>>a[i];
    ll res1=f(p1),res2=f(p2);
    if(res1==res2)cout<<"Draw";
    else if(res1>res2)cout<<"Bodya";
    else cout<<"Sasha";
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