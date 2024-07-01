#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

int T;
int cal(string &a,string &b){
    int n=a.length();
    int m=b.length();
    int ans=n+m;
    for(int j=0;j<m;j++){
        int l=j;
        for(int i=0;i<n;i++){
            if(l<m&&a[i]==b[l]){
                l++;
            }
        }
        ans=min(ans,n+m-l+j);
    }
    return ans;
}
void solve(){
    string a,b;
    cin>>a>>b;
    int n=a.length();
    int m=b.length();
    cout<<cal(a,b);
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