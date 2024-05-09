/*
 * Author: Ram
 * Date: 2024-04-30
 * Source: https://codeforces.com/contest/1972/problem/C
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll=long long;
const int N=2e5+5;
ll a[N];
int T;
void solve(){
    ll n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    sort(a,a+n);
    ll pre=a[0];
    int i=1;
    for(;i<n;i++){
        ll dif=(a[i]-pre)*i;
        if(dif<=k)k-=dif;
        else {
            pre+=k/i;
            k-=k/i*i;
            i-=k;
            break;
        }
        pre=a[i];
    }
    if(i==n)pre+=k/n,k-=k/n*n,i-=k;
    ll ans=(pre-1)*n+1+n-i;
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