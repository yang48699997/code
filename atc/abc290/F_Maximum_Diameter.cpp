#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define endl '\n'

int T;
const int N=1e6+5;
const int mod=998244353;

ll powMod(ll x,ll y){
    while(y){
        ll t = y;
        y = x % y;
        x = t;
    };
    return x;
};

void solve(){
    int n;
    cin>>n;
    
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