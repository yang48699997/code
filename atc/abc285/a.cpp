#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int a,b;
    cin>>a>>b;
    if(a>b)swap(a,b);
    if(b/2==a)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}