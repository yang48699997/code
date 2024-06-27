#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    int n;
    cin>>n;
    int x,y;
    while(n--){
        cin>>x>>y;
        sx=x*2-sx;
        sy=y*2-sy;
    }
    // cerr<<sx<<' '<<sy<<endl;
    if(sx==tx&&sy==ty)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}