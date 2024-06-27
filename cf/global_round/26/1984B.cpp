#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
int T;
void solve(){
    ll n;
    cin>>n;
    if(n%10==9){
        cout<<"NO";
        return;
    }
    int l=n%10;
    n/=10;
    while(n){
        int cur=n%10;
        cur-=1;
        if(cur==-1){
            cout<<"NO";
            return;
        }
        l=n%10;
        n/=10;
    }
    if(l==1)cout<<"YES";
    else cout<<"NO";
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