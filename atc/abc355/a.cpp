#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int a,b;
    cin>>a>>b;
    if(a==b){
        cout<<-1;
        return;
    }
    for(int i=1;i<=3;i++){
        if(a!=i&&b!=i){
            cout<<i;
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