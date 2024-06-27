#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(m);
    for(int i=0;i<m;i++)cin>>a[i];
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int x;
            cin>>x;
            a[j]-=x;
        }
    }
    for(int i=0;i<m;i++){
        if(a[i]>0){
            cout<<"No";
            return;
        }
    }
    cout<<"Yes";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}