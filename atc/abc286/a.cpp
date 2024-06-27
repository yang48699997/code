#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,a,b,c,d;
    cin>>n>>a>>b>>c>>d;
    vector<int> p(n+1);
    for(int i=1;i<=n;i++)cin>>p[i];
    for(int j=0;j<=b-a;j++)swap(p[a+j],p[c+j]);
    for(int i=1;i<=n;i++)cout<<p[i]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}