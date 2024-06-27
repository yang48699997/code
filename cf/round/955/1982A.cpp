#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int x1,y1;
    cin>>x1>>y1;
    int x2,y2;
    cin>>x2>>y2;
    if(x1>y1){
        swap(x1,y1);
        swap(x2,y2);
    }
    if(x2>=y2)cout<<"NO";
    else cout<<"YES";
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