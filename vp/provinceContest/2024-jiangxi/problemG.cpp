#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    int a;
    char b;
    int res=0;
    while(n--){
        cin>>a>>b;
        if(b=='A'){
            continue;
        }else{
            res=(res+a%5*(b-'0'))%5;
        }
    }
    if(res==0)cout<<"Yes";
    else cout<<"No";
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