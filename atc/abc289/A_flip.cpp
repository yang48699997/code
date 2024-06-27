#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    for(char ch:s){
        if(ch=='0')cout<<1;
        else cout<<0;
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}