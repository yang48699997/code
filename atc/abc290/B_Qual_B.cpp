#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,k;
    cin>>n>>k;
    string s;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='x')continue;
        if(k)k--;
        else s[i]='x';
    }
    cout<<s;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}