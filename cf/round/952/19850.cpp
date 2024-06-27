#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    string a,b;
    cin>>a>>b;
    swap(a[0],b[0]);
    cout<<a<<' '<<b;

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