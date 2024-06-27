#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n,t;
    cin>>n>>t;
    vector<int> l(n,n),c(n,n),a(t+1);
    for(int i=1;i<=t;i++)cin>>a[i];
    int ll=n,r=n;
    for(int i=1;i<=t;i++){
        int x=(a[i]-1)/n;
        int y=(a[i]-1)%n;
        l[x]--;
        c[y]--;
        if(x==y)ll--;
        if(x+y==n-1)r--;
        if(l[x]==0||c[y]==0||ll==0||r==0){
            cout<<i;
            return;
        }
    }
    cout<<-1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}