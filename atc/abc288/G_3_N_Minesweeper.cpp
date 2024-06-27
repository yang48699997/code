#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> pw(n+1,1);
    for(int i=1;i<=n;i++)pw[i]=3*pw[i-1];
    vector<int> a(pw[n]);
    for(int i=0;i<pw[n];i++)cin>>a[i];
    for(int i=n-1;i>=0;i--){
        for(int j=0;j<pw[n];j++){
            if(j/pw[i]%3!=0)continue;
            int w0=a[j],w1=a[j+pw[i]],w2=a[j+pw[i]*2];
            a[j+pw[i]*2]=w1-w0;
            a[j]=w1-w2;
            a[j+pw[i]]=w1-a[j]-a[j+2*pw[i]];
        }
    }
    for(int i=0;i<pw[n];i++)cout<<a[i]<<" ";
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}