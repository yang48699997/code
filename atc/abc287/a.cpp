#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    int cnt=0;
    string s;
    for(int i=0;i<n;i++){
        cin>>s;
        if(s=="For")cnt++;
    }
    if(cnt*2>n)cout<<"Yes";
    else cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}