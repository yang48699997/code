#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
using ll = long long;
void solve(){
    ll sx,sy;
    cin>>sx>>sy;
    ll tx,ty;
    cin>>tx>>ty;
    ll ans=abs(ty-sy);
    if((sx+sy)%2==1)sx--;
    if(tx>=sx){
        ans+=max(0LL,(tx-sx-ans)/2);
    }else{
        ans+=max(0LL,(sx-tx-ans+1)/2);
    }
    cout<<ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}