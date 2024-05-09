/*
 * Author: Ram
 * Date: 2024-05-01
 * Source: https://codeforces.com/contest/1972/problem/D2
*/
#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
int gcd(int a,int b){
    while(b){
        int temp=b;
        b=a%b;
        a=temp;
    }
    return a;
}
void solve(){
    int n,m;
    cin>>n>>m;
    ll ans=0;
    for(int i=1;i*i<=n;i++){
        for(int j=1;j*j<=m;j++){
            if(gcd(i,j)!=1)continue;
            ans+=min(n/(i*(i+j)),m/(j*(i+j)));
        }
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