#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
void solve(){
    int n,m;
    cin>>n>>m;
    vector<vector<int>> a(n,vector<int> (m));
    vector<vector<int>> b(n,vector<int> (m));
    vector<int> ar(n*m+1),br(n*m+1);
    vector<int> ac(n*m+1),bc(n*m+1);
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>a[i][j],ar[a[i][j]]=i,ac[a[i][j]]=j;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++)cin>>b[i][j],br[b[i][j]]=i,bc[b[i][j]]=j;
    }
    vector<int> c(m);
    for(int i=0;i<n;i++){
        for(int j=1;j<m;j++){
            if(br[a[i][j]]!=br[a[i][0]]){
                cout<<"NO";
                return;
            }
        }
    }
    int r=br[a[0][0]];
    for(int i=0;i<m;i++){
        c[i]=ac[b[r][i]];
        // cerr<<i<<":"<<c[i]<<endl;
    }
    for(int i=1;i<n;i++){
        int tr=br[a[i][0]];
        for(int j=0;j<m;j++){
            if(a[i][c[j]]!=b[tr][j]){
                cout<<"NO";
                return;
            }
        }
    }
    cout<<"YES";
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