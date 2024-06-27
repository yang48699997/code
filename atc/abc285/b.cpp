#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    string s;
    cin>>n>>s;
    int mx=0;
    for(int i=1;i<n;i++){
        int res=0;
        for(int j=0;j<n-i;j++){
            if(s[j]!=s[j+i])res++;
            else break;
        }
        cout<<res<<endl;
    }   
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}