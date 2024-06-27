#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    if(a[0]==a.back()){
        cout<<"NO";
        return;
    }
    cout<<"YES\n";
    if(a[0]==a[1])cout<<"BR";
    else cout<<"RB";
    for(int i=2;i<n;i++){
        cout<<"R";
    }
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