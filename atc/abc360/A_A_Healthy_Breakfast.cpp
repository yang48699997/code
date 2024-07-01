#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    string s;
    cin>>s;
    int ok=0;
    for(int i=0;i<3;i++){
        char c=s[i];
        if(c=='R'){
            cout<<"Yes";
            return ;
        }
        if(c=='M'){
            cout<<"No";
            return;
        }
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}