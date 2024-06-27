#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

void solve(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    int i=0,j=1,k=0;
    while(i<n&&j<n&&k<n){
        if(a[(i+k)%n]==a[(j+k)%n]){
            k++;
            continue;
        }else if(a[(i+k)%n]<a[(j+k)%n])j+=k+1;
        else i+=k+1;
        if(i==j)j++;
        k=0;
    }
    int ans=min(i,j);
    for(int ii=0;ii<n;ii++)cout<<a[(ii+ans)%n]<<' ';
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    cout<<endl;
    return 0;
}