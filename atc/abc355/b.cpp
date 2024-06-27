#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,m;
    cin>>n>>m;
    vector<int> a(n),b(m),c(n+m);
    for(int i=0;i<n;i++)cin>>a[i],c[i]=a[i]; 
    for(int i=0;i<m;i++)cin>>b[i],c[i+n]=b[i];
    sort(c.begin(),c.end());
    for(int i=0;i<n;i++){
        for(int k=i+1;k<n;k++)
        for(int j=0;j<n+m-1;j++){
            if(c[j]==a[i]&&c[j+1]==a[k]){
                cout<<"Yes";
                return;
            }else if(c[j]==a[k]&&c[j+1]==a[i]){
                cout<<"Yes";
                return;
            }
        }
    } 
    cout<<"No";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}