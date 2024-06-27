#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int x,y,k;
    cin>>x>>y>>k;
    while(k){
        int l=x%y;
        int d=y-l;
        x+=min(d,k);
        k-=min(d,k);
        while(x%y==0)x/=y;
        // cerr<<x<<' '<<y<<' '<<k<<endl;
        if(x==1){
            cout<<(k%(y-1)+x);
            return;
        }
    }
    cout<<x;
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