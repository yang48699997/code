#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int x,y;
    for(int i=0;i<n;i++){
        cin>>x>>y;
        if(y>=-1)cout<<"YES";
        else cout<<"NO";
        cout<<endl;
    } 
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}