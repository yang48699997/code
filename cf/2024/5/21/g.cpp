#include <bits/stdc++.h>
using namespace std;
using ll=long long;
#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    ll l,r,y,x;
    vector<array<ll,3>> p(n);
    for(int i=0;i<n;i++)cin>>p[i][1]>>p[i][2]>>p[i][0];
    sort(p.begin(),p.end(),[](auto &a,auto &b){
        if(a[0]!=b[0])return a[0]>b[0];
        else return a[1]<b[1];
    });
    cin>>x>>y;
    int cur=0;
    while(cur<n){
        if(p[cur][0]>y){
            cur++;
            continue;
        }
        if((x-p[cur][1])*(x-p[cur][2])<0){
            x=p[cur][2];
            y=p[cur][0];
        }
        cur++;
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