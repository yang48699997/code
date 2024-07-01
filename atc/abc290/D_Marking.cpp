#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int gcd(int x,int y){
    while(y){
        int t=y;
        y=x%y;
        x=t;
    }
    return x;
}
int T;
void solve(){
    int n,d,k;
    cin>>n>>d>>k;
    int g=gcd(n,d);
    int a=n/g;
    int b=d/g;
    int t=(k-1)/a;
    int ans=t+(long long)(k-t*a-1)*d%n;
    cout<<ans;
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